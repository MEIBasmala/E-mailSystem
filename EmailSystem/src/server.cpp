#include"server.h"

server(vector<int> IDs)
{
  data_base=IDs;
}

bool server::send(email &mail)
{
    // input address of destination and try to send
    for (int i = 0; i <data_base.size(); i++)
    {
    // if it's sent return true
        if (data_base[i] == mail.receiver.id)
        {
            receive(mail);
            return true;
        }
    }

    // if it's not sent put it on anothe queue " copyQueue" and return false
    copyQueue.push(mail);
    return false;
}

void server::process()
{  
  // eroor email to send it to the email sender in case his email can not be sent
    string error_massege="Your email did note reach the destination, please check the receiver account. "
    email ERROE_EMAIL(,, error_massege); 
    // use send function
    for (int i = 0; i < mainQueue.size(); i++){
      // dequeue one element from queue and send then check
      email temp = mainQueue.front();
      send(mail );
      mainQueue.pop();
    }
    // if initial queue empty, go to resend function to proccess emails in copyqueue
    
       for (int j = 0; j < copyQueue.size(); j++)
    {
        email temp = copyQueue.front();
        if(resend(temp))
        {
        }
        else
        { ERROE_EMAIL.receiver=temp.sender;
          send(ERROE_EMAIL);
        }
        copyQueue.pop();  
    }
  
  
}

void server::receive( email &mail)
{
    mail.receiver.mailBox.push(mail);
}

bool server::resend(email &mail)
{
    for (int i = 0; i < 3; i++)
        {
            if (send(mail))
               return true;
        }
  return false;
}
