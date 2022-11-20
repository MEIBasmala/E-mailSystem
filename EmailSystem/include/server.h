#ifndef __SERVER_H__
#define __SERVER_H__
#include "email.h"
#include <vector>
#include<queue>

class Server
{

public:

    Server(std::vector<user> ids);
    //construvter for the BST
    //Server();
    //constructer for the AVL
    //Server();
    void send_to_server(const email& mail);
    void process();
    void sign_up(const user& newuser);


private:
  std::vector<user> data_base;
  std::queue<email> mainQueue;
  std::queue<email> copyQueue;
  bool resend(email &mail);
  bool send(email &mail);
  void receive(email &mail);

};

#endif
