#ifndef __EMAIL_H__
#define __EMAIL_H__
#include <iostream>
#include <string>
#include <stack>
#include <queue>


class email;

struct user
{
    int id;
    std::string name;
    std::stack<email> mailBox;

};

class email{

private:

    user sender;
    user receiver;
    std::string text;

public:
    email();
    email( const user &s,const user &r ,const std::string & msg);
    email( const user &s,const user &r  , std::string && msg);
    bool send(user USER,email &mail);
    //bool send(user USER, email &&emailToSend);
    void process( email &);
    void receive(email &mail);
    void resend(); // void ? bool ?
    ///we need a function that generate a percentage of probability of sending the mail


    ~email(){};


};



#endif // __EMAIL_H__
