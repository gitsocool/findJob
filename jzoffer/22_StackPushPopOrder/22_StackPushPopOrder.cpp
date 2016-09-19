#include<iostream>
#include<stack>
//#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::stack;
bool IsPopOrder(const int * push,const int *pop,int length)
{    bool is=false;
     if(push==NULL || pop==NULL || length<=0)
            return is;

    const int * pushNext=push;
    const int * popNext=pop;
    stack<int> sta;
     while(popNext-pop!=length)
     {
        while(sta.empty() || sta.top()!=*popNext)
         {   if(pushNext-push==length) break;
             sta.push(*pushNext++);
         }
 
       if(sta.top()!=*popNext) break; 
             popNext++;
             sta.pop();
    }
       
   if(sta.empty() && popNext-pop==length)
       is=true;
   return is;
}
void forTest(char * testName,const int * push,const int *pop,int length)
{
    cout<<testName<<endl; 
     bool is=IsPopOrder(push,pop,length);
     if(is)
     cout<<  "is true"<<endl;  
     else
     cout<<"is false"<<endl;
}

void test1()
{
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length] = {4, 5, 3, 2, 1};
    forTest("test1",push,pop,length);
}

void test2()
{
      const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
   forTest("test2",push,pop,nLength);
 
}

void test3(){

     const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};
   forTest("test3",push,pop,nLength);

}


void test4()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 1, 2}; 
   forTest("test4",push,pop,nLength);

}

void test5()
{
    const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {2};
     forTest("test5",push,pop,nLength);

}

void test6(){
       const int nLength = 1;
    int push[nLength] = {1};
    int pop[nLength] = {1};
   forTest("test6",push,pop,nLength);
}

void test7(){

  forTest("test7",NULL,NULL,0);
}
int main()
{
test1();
test2();
test3();
test4();
test5();
test6();
test7();

return 0;
}
