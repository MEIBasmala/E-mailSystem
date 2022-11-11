#ifndef __EMAIL_H__
#define __EMAIL_H__

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>

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
    std::string mail;
    int counter;


public:
    email();
    email( const user &s,const user &r ,const std::string & msg);
    email( const user &s,const user &r  , std::string && msg);
    void send(const email &);
    void process(const email &);
    bool receive();
    bool check();
    void resend(); // void ? bool ?
    static std::queue<email> mainQueue;
    static std::queue<email> copyQueue;
    ~email();
 

};

#endif // __EMAIL_H__
