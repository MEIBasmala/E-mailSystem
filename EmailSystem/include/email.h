#ifndef __EMAIL_H__
#define __EMAIL_H__
#include <iostream>
#include <string>
#include <stack>


 class email;

struct user
{
    int id;
    std::string name;
    std::stack<email> mailBox;
};

class email
{

private:
    user sender;
    user receiver;
    std::string text;

public:
    email();
    email(const user &s, const user &r, const std::string &msg);
    email(const user &s, const user &r, std::string &&msg);

    void set_sender(const user &newsender);
    void set_receiver(const user &newreceiver);

    void set_text(std::string);
    std::string get_text();

    user get_sender() const;
    user get_receiver() const;

    std::string get_sender_name() const;
    std::string get_receiver_name() const;


    ~email(){};
};


#endif // __EMAIL_H__
