#include "email.h"
#include <stack>
#include <queue>
#include <unordered_map>


email::email() = default;
email::email( const std::string & str){
};

email::email( std::string && str){

};

void email::send(const email &receiver) //utility fun ??
{

    //input address of destination and try to send

}
void email::process(const email &)
{
    // dequeue one element from queue and send then check
    // use send and check function
    // if it's sent go to next element in the queue and process again ( RECURSION ( parameter == queue dequeue ))
    // if it's not sent put it on another WaitList queue and continue
    // if initial queue empty, go to resend function

}
bool email::receive(){ //utility fun ??
    //add email to stack
}
bool email::check(){ //utility fun ??
    //yes->continue
    //how to know -> stack size++?
    //no->copy to new queue


}

void email::resend(){
    // when ? -> initial queue is empty
    // try recursion with checking counter
}
