/***
* Team leader : Farez Samah Ikram
***/
#include"BinarySearchTree.h"
#include"server_BST.h"
#include<fstream>

Server_BST::Server_BST()
{
    CreateDataBase();
}
bool Server_BST::sign_up(const user &newuser)
{
    if (!check(newuser))
    {
        std::fstream FF;
        FF.open("DataBase.txt", std::ios::app);
        FF << "\n" << newuser.name << " " ;
        FF << newuser.id ;
        DataBase_BST.insert(newuser.id);
        FF.close();
        return true;
    }

    else
    {
        std::cout << "USER ALREADY EXISTS !! " << std::endl;
        return false;
    }
}
// put the email in mainqueue for processing
bool Server_BST::send_to_server(const email &mail)
{
    if (check(mail.get_receiver()))
    {
        mainQueue.push(mail);
        return true;
    }

    else
    {
        std::cout << "\nOperation can not be done,receiver does not exist.\n" ;
        copyQueue.push(mail);
        return false;
    }
}

bool Server_BST::send(email &mail)
{
    std::cout << "\nSending Request . . .\n";
// if it's sent return true
    if(DataBase_BST.contains(mail.get_receiver().id))
    {
        receive(mail);
        InputIntoFile(mail);
        return true;
    }
// if it's not sent put it on another queue " copyQueue" and return false
    copyQueue.push(mail);
    return false;
}
void Server_BST::process()
{

    // error email to send it to the email sender in case his email can not be sent
    std::string error_massege = "Your email did note reach the destination, please check the receiver account. ";
    email ERROR_EMAIL;

    // use send function
    for (int i = 0; i < mainQueue.size(); i++)
    {
        // dequeue one element from queue and send then check
        email temp = mainQueue.front();
        send(temp);
        mainQueue.pop();
    }
    // if main queue empty, go to  process emails in copy queue

    for (int j = 0; j < copyQueue.size(); j++)
    {
        email temp = copyQueue.front();
        if (!resend(temp))
        {
            ERROR_EMAIL.set_receiver(temp.get_sender());
            ERROR_EMAIL.set_text(error_massege);
            send(ERROR_EMAIL);
        }

        copyQueue.pop();
    }
}

bool Server_BST::receive(email &mail)
{
    int size = mail.get_receiver().mailBox.size();

    std::cout << "\nRecieving Request . . .\n";
    mail.get_receiver().mailBox.push(mail);

    if (mail.get_receiver().mailBox.size() > size)
        return true;

    return false;
}

void Server_BST::CreateDataBase()
{

    std::ifstream FF;
    FF.open("DataBase.txt");
    for (int i = 0; i < 1500; i++)
    {
        user temp;
        FF >> temp.name;
        FF >> temp.id;
        DataBase_BST.insert(temp.id);
    }
}

bool Server_BST::resend(email &mail)
{
    for(int i=0 ; i<3 ; i++)
    {
        // if it's sent return true
        if (DataBase_BST.contains(mail.get_receiver().id))
        {
            receive(mail);
            InputIntoFile(mail);
            return true;
        }
    }
    // if it's not sent put it on anothe queue " copyQueue" and return false
    std::cout << "\nNOT SENT\n";
    return false;
}

// Check if the user already exists in the DataBase;
bool Server_BST::check(user USER)
{

    return DataBase_BST.contains(USER.id);

}

void Server_BST::InputIntoFile(email &mail)
{
    std::cout << "\Inputing into File . . .\n";
    std::fstream FF;
    FF.open("Mails.txt", std::ios::app);
    FF << "\n------------------------------------\n";
    FF << "\nFrom:" << mail.get_sender().name ;
    FF << "\nTo:" << mail.get_receiver().name  ;
    FF << "\nText:" << mail.get_text()  ;
    FF << "\n\n------------------------------------\n";
    FF.close();
}


