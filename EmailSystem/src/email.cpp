#include "email.h"

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
void email::print()
{
    std::cout<<"From : "<<this->get_sender_name()<<"\n";
    std::cout<<"To : "<<this->get_receiver_name()<<"\n";
    std::cout<<"\n"<<get_text()<<"\n";
}

std::string email::get_text(std::string)
{
    return this->text;
}
