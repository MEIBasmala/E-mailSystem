#include <iostream>
#include <time.h>
#include <vector>
#include "email.h"
#include "server.h"


using std::vector;

int IDchecker(int INPUT)
{

    while (true)
    {
        if (INPUT < 110000 || INPUT > 119999)
        {
            std::cout << "Invalid ID Retry again\nEnter ID:";
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

    bool BOOL = true;
    int input;
    while (BOOL)
    {

        std::cout << "--------------------------------------------------------------------------\n";
        std::cout << "What do you want to do ?\n";
        std::cout << " [ 1 ] -> SEND AN EMAIL\n";
        std::cout << " [ 2 ] -> SIGN UP\n";
        std::cout << " [ 3 ] -> SHUT DOWN SERVER\n";
        std::cout << "Remark : All IDs are of the form 11****\n ";
        std::cout << "--------------------------------------------------------------------------\n";

        std::cout << "==>";
        std::cin >> input;

        if (input == 1)
        {

            std::cout << "Welcome to our services center,Please enter the sender and reciever info\n " << std::endl;

            user sender;
            user receiver;
            std::string txt;

            std::cout << "Sender's name :";
            std::cin >> sender.name;
            std::cout << "Sender's ID :";
            std::cin >> sender.id;
            sender.id = IDchecker(sender.id);

            std::cout << "Reciever's name :";
            std::cin >> receiver.name;
            std::cout << "Reciever's ID :";
            std::cin >> receiver.id;

            std::cout << "Enter text : \n\t";
            getline(std::cin >> std::ws, txt);

            email new_mail(sender, receiver, txt);

            EmailServer.send_to_server(new_mail);

            clear();
        }

        if (input == 2)
        {

            std::cout << "WELCOME TO THE USER CENTER !\nTo Sign up, enter your name and ID number\nPlease Make Sure The ID is of the Format 11**** " << std::endl;

            user NewUser;

            std::cout << "Your Name :";
            std::cin >> NewUser.name;
            std::cout << "Your ID :";
            std::cin >> NewUser.id;
            NewUser.id = IDchecker(NewUser.id);

            EmailServer.sign_up(NewUser);

        clear();
        }

        if (input == 3)
            BOOL = false;
    }

    std::cout << "THANK YOU FOR USING OUR SERVICES, SEE YA!! ";


}
