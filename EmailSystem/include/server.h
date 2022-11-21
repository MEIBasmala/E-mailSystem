#ifndef __SERVER_H__
#define __SERVER_H__
#include "email.h"
#include <vector>
#include<queue>

class Server
{

public:
    Server();
    bool send_to_server(const email &mail);
    void process();
    bool sign_up(const user &newuser);
    


private:
    std::vector<user> DataBase;
    std::queue<email> mainQueue;
    std::queue<email> copyQueue;
    bool resend(email &mail);
    bool send(email &mail);
    bool receive(email &mail);
    bool check(user USER);
    void CreateDataBase();
};

#endif
