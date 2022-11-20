#include <iostream>
#include "email.h"
#include "server.h"
#include"time.h"
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int main()
{
    int BaseSize = 1000;


    std::vector<user> DataBase;
    for(int i=0; i< BaseSize; i++ ){
        user temp;
        temp.id= rand();
        DataBase.push_back(temp);
    }

    Server Email_server(DataBase);

    bool BOOL = true;
    int input;
    while (BOOL)
    {

        std::cout << "WHAT DO U WANNA DO ?\n";
        std::cout << " [ 1 ] -> SEND AN EMAIL\n";
        std::cout << " [ 2 ] -> SIGN UP\n" ;
        std::cout << " [ 3 ] -> SHUT DOWN SERVER\n";
        std::cout<<"Remark : You have to sign up to benefit from our services.\n ";
        std::cin >> input;

        if (input == 1)
        {
            user sender;
            user receiver;
            std::string txt;

            std::cout << "ENTER UR NAME ";
            std::cin >> sender.name;
            std::cout << "ENTER UR ID";
            std::cin >> sender.id;


            std::cout << "ENTER RECIEVER NAME ";
            std::cin >> receiver.name;
            std::cout << "ENTER RECIEVER ID";
            std::cin >> receiver.id;

            std::cout << "ENTER UR TEXT";
            getline(std::cin , txt);

            email new_mail(sender, receiver, txt);
            Email_server.send_to_server(new_mail);

        }

        if(input == 2){

            user NewUser;

            std::cout << "ENTER UR NAME ";
            std::cin >> NewUser.name;
            std::cout << "ENTER UR ID";
            std::cin >> NewUser.id;

            Email_server.sign_up(NewUser);


}
        if (input == 3)
            BOOL = false;


        system("cls");
    }

    cout << "THANK YOU FOR USING OUR SERVICES, SEE YA!! ";

    return 0;
}
