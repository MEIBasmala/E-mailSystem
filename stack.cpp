#ifndef STACK_H
#define STACK_H

#include <vector>
using namespace std;

template<typename T>
class stack
{
  public:
    stack() {}
    stack(int size)
    {
     elements.resize(size);
    }
    bool push(const T& x)
    {
      elements.push_back(x);
    }
    bool pop()
    { 
      elements.pop_back();
    }
    void print()
    {
      for(auto T& i : elements )
      cout<<i<<"\n";
    }
  private:
    vector<T> elements;
};


#endif 

