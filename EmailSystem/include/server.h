#ifndef __SERVER_H__
#define __SERVER_H__



class Server
{

public:
    
    server(int []);
    //construvter for the BST
    server();
    //constructer for the AVL
    server();
    bool send(user USER,email &mail);
    void process( email &);
    void receive(email &mail);
    void resend();


private:
  vector<int> data_base;  
  std::queue<email> mainQueue;
  std::queue<email> copyQueue;




}
