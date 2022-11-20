#ifndef __SERVER_H__
#define __SERVER_H__
#include "email.h"
#include "vector"


class Server
{

public:
    
    server(vector<int>);
    //construvter for the BST
    server();
    //constructer for the AVL
    server();
    bool send(email &mail);
    void process();
    void receive(email &mail);
    


private:
  vector<int> data_base;  
  std::queue<email> mainQueue;
  std::queue<email> copyQueue;
  bool resend();



}
