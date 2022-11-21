#ifndef __SERVER_BST_H__
#define __SERVER_BST_H__
#include "email.h"
#include"BinarySearchTree.h"
#include<queue>
class Server_BST
{

public:
    Server_BST();
    bool send_to_server(const email &mail);
    void process();
    bool sign_up(const user &newuser);



private:
    //using a BST of ids for the part B
    BinarySearchTree<int> DataBase_BST;
    std::queue<email> mainQueue;
    std::queue<email> copyQueue;
    bool resend(email &mail);
    bool send(email &mail);
    bool receive(email &mail);
    bool check(user USER);
    void CreateDataBase();
};

#endif