#include "email.h"



email::email()
{
}
email::email(const user &s, const user &r, const std::string &msg)
{
    this->sender = s;
    this->receiver = r;
    this->text= msg;
    mainQueue.push(*this);
};

email::email(const user &s, const user &r, std::string &&msg)
{
    this->sender = s;
    this->receiver = r;
    this->text = std::move(msg);
    mainQueue.push(*this);
};

/*bool email::check(const email &address){ //utility fun ??
// yes->continue
// how to know -> stack size++?
// no->copy to new queue
//}*/

/*bool email::send(user arr[10], email &&mail) // utility fun ??
{
    // input address of destination and try to send
    for (int i = 0; i < 10; i++)
    {
        if (arr[i].id == mail.receiver.id)
        {
            mail.receiver.mailBox.push(mail);
            return true;
        }

        else
        {
            copyQueue.push(mail);
        }
    }
    return false;
}*/

bool email::send(user USER,email &mail) // utility fun ??
{
    // input address of destination and try to send
    for (int i = 0; i < 10; i++)
    {

    // if it's sent return true
        if (USER.id == mail.receiver.id)
        {
            mail.receiver.mailBox.push(mail);
            return true;
        }
    }

    // if it's not sent put it on anothe queue " copyQueue" and return false
    copyQueue.push(mail);
    return false;
}

void email::process(email &mail)
{
    // dequeue one element from queue and send then check
    email temp = mainQueue.back();
    mainQueue.pop();
    // use send function
    for (int i = 0; i < mainQueue.size(); i++){
        send(temp.receiver, mail );
    }
    // if initial queue empty, go to resend function
    if(mainQueue.size() == 0){
        resend();
    }
}

void email::receive( email &mail)
{ // utility fun ?
    // add email to stack
    mail.receiver.mailBox.push(mail);

}

void email::resend()
{
    // when ? -> initial queue is empty
    for (int j = 0; j < copyQueue.size(); j++)
    {
        email temp = copyQueue.back();
        for (int i = 0; i < 3; i++)
        {
            if (send(temp.receiver, temp))
            {
                copyQueue.pop();
                continue;
            }
        }
    }
    // try recursion with checking counter
}
