#ifndef EMAIL_H
#define EMAIL_H
#include <iostream>
#include <string>


class email{

    email();
    email( std::string && str);
    email( const std::string & str);
    void send(const email &);
    void process(const email &);
    bool receive();
    bool check();
    void resend(); // void ? bool ?

private:
    struct user
{
    int id;
    std::string name;
};

    user sender;
    user receiver;
    std::string mail;
    int counter;

};

#endif // EMAIL_H
