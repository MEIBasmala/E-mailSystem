#include "email.h"
/*
email::email(){
    mail = "";

} */
email::email( const user &s,const user &r ,const std::string & msg): sender(s),receiver(r),mail(msg)
{

};

email::email( const user &s,const user &r  , std::string && msg):sender(s),receiver(r),mail(std::move(msg))
{

};

bool email::check(){ //utility fun ??
    //yes->continue
    //how to know -> stack size++?
    //no->copy to new queue
    


}
void email::send(const email &address) //utility fun ??
{
    //input address of destination and try to send
    address.receiver;
    


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

void email::resend(){
    // when ? -> initial queue is empty
    // try recursion with checking counter
}
