#include<iostream>
#include<math.h>
#include<memory>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;


/*..............................*/
void Print1ToMaxOfNDigits_1(int n)
{
    int max=pow(10,n)-1;

    for(int i=1;i<=max;i++)
      cout<<i<<" ";
   cout<<endl;
   
 
}

//................................................
void Print1ToMaxOfNDigits_2(int n)
{
        if(n<0) return ;
      
     char *number=new char[n+1];
     char *max=new char[n+1];
    
      memset(number,'0',n);
      memset(max,'9',n);
                   
     while(strcmp(number,max)<=0)
             {
                   cout<<*number<<"\t";
                   *number=*number+1;  
             }
   cout <<endl;

    delete []number;
     delete []max;
}




//..................test for Print1ToMaxOfNDigits_1(int n) ....................
void test1()
{   int n;
    cout<<" please input the n: "<<endl;
   cin >> n;

  Print1ToMaxOfNDigits_1(n);
     
}


void test2()
{   int n;
    cout<<" please input the n: "<<endl;
   cin >> n;

  Print1ToMaxOfNDigits_2(n);
     
}

int main()
{
// test1();  
 test2();    
   return 0;
}
