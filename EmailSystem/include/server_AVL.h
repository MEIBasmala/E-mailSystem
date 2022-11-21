/***
* Team leader : Farez Samah Ikram
***/
#ifndef __SERVER_AVL_H__
#define __SERVER_AVL_H__
#include "email.h"
#include"AVLtree.h"
#include<queue>
class Server_AVL
{

public:
    Server_AVL();
    bool send_to_server(const email &mail);
    void process();
    bool sign_up(const user &newuser);

private:
    //using a vector for part A
    AVL<int> DataBase_AVL;
    std::queue<email> mainQueue;
    std::queue<email> copyQueue;
    bool resend(email &mail);
    bool send(email &mail);
    bool receive(email &mail);
    bool check(user USER);
    void CreateDataBase();
    void InputIntoFile(email &);
};

#endif
