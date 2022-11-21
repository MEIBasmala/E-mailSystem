/***
* Team leader : Farez Samah Ikram
***/
#include "email.h"
#include<fstream>

email::email()
{
}

email::email(const user &s, const user &r, const std::string &msg)
{
    this->sender = s;
    this->receiver = r;
    this->text= msg;
};

email::email(const user &s, const user &r, std::string &&msg)
{
    this->sender = s;
    this->receiver = r;
    this->text = std::move(msg);

};

void email::set_sender(const user &newsender)
{
    this->sender=newsender;
}

void email::set_receiver(const user &newreceiver)
{
    this->receiver=newreceiver;
}

user email::get_sender() const
{
    return this->sender;
}

user email::get_receiver() const
{
    return this->receiver;
}

void email::set_text(std::string message)
{
    this->text=message;
}

std::string email::get_sender_name() const
{
    return this->get_sender().name;
}

std::string email::get_receiver_name() const
{
    return this->get_receiver().name;
}

std::string email::get_text( )
{
    return this->text;
}

void email::printMails()
{
    std::fstream FF;
    FF.open("Mails.txt");

    for (int i = 0; i < 1500; i++)
    {
        std::string ss;
        std::cout << FF.rdbuf();
    }
}
