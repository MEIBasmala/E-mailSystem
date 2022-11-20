#include "email.h"



email::email()
{
}
email::email(const user &s, const user &r, const std::string &msg)
{
    this->sender = s;
    this->receiver = r;
    this->text= msg;
    mainQueue.push(*this);
};

email::email(const user &s, const user &r, std::string &&msg)
{
    this->sender = s;
    this->receiver = r;
    this->text = std::move(msg);
    mainQueue.push(*this);
};

void email::set_sender(const user &newsender)
{
    this->sender=newsender;
}
void email::set_receiver(const user &newreceiver)
{
    this->receiver=newreceiver;
}
