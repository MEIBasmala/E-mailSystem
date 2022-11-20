#include "email.h"


email::email()
{
}
email::email(const user &s, const user &r, const std::string &msg)
{
    sender = s;
    receiver = r;
    text = msg;
};

email::email(const user &s, const user &r, std::string &&msg)
{
    sender = s;
    receiver = r;
    text = std::move(msg);
};

void email::set_sender(const user &newsender)
{
    sender = newsender;
}
void email::set_receiver(const user &newreceiver)
{
    receiver = newreceiver;
}
user email::get_sender() const
{
    return sender;
}
user email::get_receiver() const
{
    return receiver;
}
void email::set_text(std::string message)
{
    text = message;
}
std::string email::get_sender_name() const
{
    return get_sender().name;
}
std::string email::get_receiver_name() const
{
    return get_receiver().name;
}

std::string email::get_text()
{
    return "    " + text;
}
void email::print()
{
    std::cout << "From : " << get_sender_name();
    std::cout << "To : " << get_receiver_name();
    std::cout << "\n-----------------------------------------------------n";
    std::cout << get_text() << std::endl;
    std::cout << "\n-----------------------------------------------------n";
}
