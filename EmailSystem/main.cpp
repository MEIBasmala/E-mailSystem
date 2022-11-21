/***
* Team leader : Farez Samah Ikram
***/
#include <iostream>
#include "email.h"
#include "server.h"
#include <time.h>
#include <vector>
#include "server_AVL.h"
#include "server_BST.h"
#include <chrono>

using std::vector;

int IDchecker(int INPUT)
{

    while (true)
    {
        if(INPUT < 110000 && INPUT > 119999)
        {
            std::cout << "Invalid ID !!!\nRetry again!!" << std::endl;
            std::cin >> INPUT;
        }
        else
            return INPUT;
    }
}

void clear()
{
    std::cout << "\x1B[2J\x1B[H";
}

int main()
{
    Server EmailServer;
    Server_BST EmailServer_BST;
    Server_AVL EmailServer_AVL;

    bool BOOL = true;
    int input;

    while (BOOL)
    {
        std::cout << "--------------------------------------------------------------------------\n";
        std::cout << "What do you want to do ?\n";
        std::cout << " [ 1 ] -> SEND AN EMAIL\n";
        std::cout << " [ 2 ] -> SIGN UP\n";
        std::cout << " [ 3 ] -> RUNNING TIME\n";
        std::cout << " [ 4 ] -> SHOW MAILS HISTORY & SHUT DOWN SERVER\n";
        std::cout << "Remark : All IDs are of the form 11****\n ";
        std::cout << "--------------------------------------------------------------------------\n";
        std::cout << "==>" ;
        std::cin >> input;

        if(input == 1)
        {
            clear();
            std::cout << "Welcome to our services center !! \nPlease enter the sender's and receiver's info !" << std::endl;
            user sender;
            user receiver;
            std::string txt;

            std::cout << "Sender's name :";
            std::cin >> sender.name;
            std::cout << "Sender's ID :";
            std::cin >> sender.id;
            sender.id = IDchecker(sender.id);

            std::cout << "Receiver's name :";
            std::cin >> receiver.name;
            std::cout << "Receiver's ID :";
            std::cin >> receiver.id;
            receiver.id = IDchecker(receiver.id);

            std::cout << "Enter your text ";
            getline(std::cin >> std::ws, txt);

            email new_mail(sender, receiver, txt);
            EmailServer.send_to_server(new_mail);
            //EmailServer_BST.send_to_server(new_mail);
            // EmailServer_AVL.send_to_server(new_mail);
        }

        if(input == 2)
        {
            clear();
            std::cout << "Welcome to our user center !\nTo Sign up, enter your name and ID number\nPlease Make Sure The ID is of the Format 11**** " << std::endl;

            user NewUser;

            std::cout << "Enter your name :";
            std::cin >> NewUser.name;
            std::cout << "Enter your ID :";
            std::cin >> NewUser.id;
            NewUser.id =IDchecker(NewUser.id);


            if(EmailServer.sign_up(NewUser))
            {
                std::cout << "Signed Up Successfully !! \nYou'll be redirected to our services center !!!" << std::endl;
            }

            /*if(EmailServer_BST.sign_up(NewUser))
            {
                std::cout << "Signed Up Successfully !! \nYou'll be redirected to our services center !!!" << std::endl;
            }

            if(EmailServer_AVL.sign_up(NewUser))
            {
                std::cout << "Signed Up Successfully !! \nYou'll be redirected to our services center !!!" << std::endl;
            }*/
        }
        if(input == 3)
        {
            clear();
            auto start=std::chrono::steady_clock::now();
            EmailServer.process();
            auto end=std::chrono::steady_clock::now();

            std::cout<<"The average time for the operation send email using vector is: "<<std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()<<" nanoseconds"<<"\n";

            /* auto start1=std::chrono::steady_clock::now();
             EmailServer_BST.process();
             auto end1=std::chrono::steady_clock::now();

             std::cout<<"The average time for the operation send email using Binary- Search Tree is: "
                      <<std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1).count()<<" nanoseconds"<<"\n";

             auto start2=std::chrono::steady_clock::now();
             EmailServer_AVL.process();
             auto end2=std::chrono::steady_clock::now();

             std::cout<<"The average time for the operation send email using AVL Tree is: "
                <<std::chrono::duration_cast<std::chrono::nanoseconds>(end2-start2).count()<<" nanoseconds"<<"\n";
                */
        }

        if(input == 4)
        {
            clear();
            email mail;
            EmailServer.process();
            mail.printMails();
            BOOL=false;
            std::cout << "THANKS FOR USING OUT SERVICE!!" <<std::endl;
        }
    }
    return 0;
}
