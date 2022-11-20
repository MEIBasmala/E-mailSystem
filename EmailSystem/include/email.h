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
    void set_sender(const user &newsender);
    void set_receiver(const user &newreceiver);
    
    ~email(){};


};



#endif // __EMAIL_H__
