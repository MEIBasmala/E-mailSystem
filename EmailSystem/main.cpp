#include<iostream>
#include"email.h"
#include "QuadraticProbing.h"

using std::cout;
using std::cin;

int main()
{
    user arr[10]={};
    for(int i=0 ; i<10 ; i++){
        user temp;
        cin>> temp.name >> temp.id ;
        arr[i]=temp ;

    }
    return 0;
}