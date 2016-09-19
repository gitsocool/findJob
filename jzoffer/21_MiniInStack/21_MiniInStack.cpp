#include<iostream>
#include<stack>
#include<assert.h>
using std::cin;
using std::cout;
using std::endl;
using std::stack;
template <typename ywd> class StackWithMin
{
 
  public:
//    StackWithMin(void) {}
 //   virtual ~StackWithMin(void) {}
    void push(const ywd & value);
    void  pop(void);
     ywd &  min();
 
   private:
   stack<ywd> data;
   stack<ywd> assist;
};

template <typename ywd>
void StackWithMin<ywd>::push(const ywd & value)
{
  data.push(value);
    if(assist.size()==0 || value <assist.top())
        assist.push(value);
     else 
        assist.push(assist.top());           
}

template <typename ywd>
void StackWithMin<ywd>::pop()
{
     assert(data.size()!=0 && assist.size()!=0);
     data.pop();
     assist.pop();
}
template<typename ywd>
ywd & StackWithMin<ywd>::min()
{
    assert(data.size()!=0 && assist.size()!=0);
     return assist.top();
}

void forTest()
{ 
  StackWithMin<int> stack;
 
  stack.push(3);
  stack.push(4);
  cout<<stack.min() <<endl;
   
  stack.push(2);
  cout<<stack.min() <<endl;

  stack.pop();
  cout<<stack.min()<<endl;
}
int main()
{
forTest();
return 0;
}
