#include"server.h"


Server::Server()
{
    CreateDataBase();
}
bool Server::sign_up(const user &newuser)
{
    if (check(newuser))
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
void Server::send_to_server(const email &mail)
{
    mainQueue.push(mail);
    process();
}

bool Server::send(email &mail)
{
    // input address of destination and try to send
    for (int i = 0; i < DataBase.size(); i++)
    {
        // if it's sent return true
        if (DataBase[i].id == mail.get_receiver().id)
        {
            receive(mail);
            return true;
        }
    }

    // if it's not sent put it on anothe queue " copyQueue" and return false
    copyQueue.push(mail);
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
        if (resend(temp))
        {
        }
        else
        {
            ERROE_EMAIL.set_receiver(temp.get_sender());
            ERROE_EMAIL.set_text(error_massege);
            send(ERROE_EMAIL);
        }

        copyQueue.pop();
    }
}

void Server::receive(email &mail)
{
    mail.get_receiver().mailBox.push(mail);
}

bool Server::resend(email &mail)
{
    for (int i = 0; i < 3; i++)
    {
        if (send(mail))
            return true;
    }
    return false;
}

void Server::CreateDataBase()
{

    std::fstream FF;
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
        DataBase[i].id == USER.id;
        return true;
    }

    return false;
}
