#ifndef __SERVER_H__
#define __SERVER_H__
#include "email.h"
#include <vector>
#include<queue>

class Server
{

public:
    Server();
    // constructor for the BST
    // Server();
    // constructor for the AVL
    // Server();
    void send_to_server(const email &mail);
    void process();
    bool sign_up(const user &newuser);
    bool check(user USER);

private:
    std::vector<user> DataBase;
    std::queue<email> mainQueue;
    std::queue<email> copyQueue;
    bool resend(email &mail);
    bool send(email &mail);
    void receive(email &mail);
    void CreateDataBase();
};

#endif
