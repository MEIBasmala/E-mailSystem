#include"server.h"
#include<fstream>
Server::Server()
{
    CreateDataBase();
}
bool Server::sign_up(const user &newuser)
{

    if (!check(newuser))
    {

        DataBase.push_back(newuser);
        return true;
    }

    else
    {
        std::cout << "USER ALREADY EXISTS !! " << std::endl;
        return false;
    }
}
// put the email in mainqueue for processing
bool Server::send_to_server(const email &mail)
{
    if (check(mail.get_receiver()))
    {
        mainQueue.push(mail);
        return true;
    }

    else
    {
        std::cout << "\nOperation can not be done,receiver does not exist.\n" ;
        return false;
    }
}

bool Server::send(email &mail)
{

    // input address of destination and try to send
    for (int i = 0; i < DataBase.size(); i++)
    {
        // if it's sent return true
        if (DataBase[i].id == mail.get_receiver().id)
        {
            return receive(mail);
        }
    }

    copyQueue.push(mail); // if it's not sent put it on another queue " copyQueue" and return false
    return false;
}

void Server::process()
{

    // error email to send it to the email sender in case his email can not be sent
    std::string error_massege = "Your email did note reach the destination, please check the receiver account. ";
    email ERROE_EMAIL;

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
            ERROE_EMAIL.set_receiver(temp.get_sender());
            ERROE_EMAIL.set_text(error_massege);
            send(ERROE_EMAIL);
        }

        copyQueue.pop();
    }
}

bool Server::receive(email &mail)
{
    int size = mail.get_receiver().mailBox.size();

    std::cout << "\nRecieving Request . . .\n";
    mail.get_receiver().mailBox.push(mail);

    if (mail.get_receiver().mailBox.size() > size)
        return true;

    return false;
}
bool Server::resend(email &mail)
{

    for (int i = 0; i < 3; i++)
    {
        if (send(mail))
            return true;
    }

    std::cout << "\nNOT SENT\n";
    return false;
}

void Server::CreateDataBase()
{

    std::ifstream FF;
    FF.open("DataBase.txt");

    for (int i = 0; i < 1500; i++)
    {
        user temp;
        FF >> temp.name;
        FF >> temp.id;
        DataBase.push_back(temp);
    }
}

// Check if the user already exists in the DataBase;

bool Server::check(user USER)
{

    for (int i = 0; i < DataBase.size(); i++)
    {
        if(DataBase[i].id == USER.id)
           return true;
    }

    return false;
}

