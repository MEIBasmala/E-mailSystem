#include <iostream>
#include "email.h"
#include"time.h"
#include <vector>

using std::cin;
using std::cout;
using std::vector;
//ask the user if he want to send a mail to an existed user or  to new one(add the new one to the data base then send)

/*bool check(vector<user> vect, user USER)
{

    for (int i = 0; i < vect.size(); i++)
    {
        vect[i].id == USER.id;
        return true;
    }

    return false;
};
*/


int main()
{
    int BaseSize = 1000;


    std::vector<user> DataBase;
    for(int i=0; i< BaseSize; i++ ){
        user temp;
        temp.id= i*i;
        DataBase.push_back(temp);
    }


    bool BOOL = true;
    int input;
    vector<user> Users;

    while (BOOL)
    {

        std::cout << "WHAT DO U WANNA DO ?";
        std::cout << " [ 1 ] - SEND AN EMAIL";
        std::cout << " [ 2 ] - SIGN UP " ;
        std::cout << " [ 3 ] - SHUT DOWN SERVER";

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

            email mail(sender, receiver, txt);
            //send here

        }

        if(input == 2){

            user NewUser;

            std::cout << "ENTER UR NAME ";
            std::cin >> NewUser.name;
            std::cout << "ENTER UR ID";
            std::cin >> NewUser.id;

            DataBase.push_back(NewUser);


}
        if (input == 3)
            BOOL = false;
    }

    cout << "THANK U FOR USING OUR SERVICES, SEE YA!! ";

    return 0;
}
