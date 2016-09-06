#include<iostream>
using std::cin;
using std::cout;
using std::endl;
long long Fibonacci_Solution1(unsigned n)
{
     int arr[2]={0,1};
     if(n<2) return arr[n];
     return Fibonacci_Solution1(n-1)+Fibonacci_Solution1(n-2);
}

long long  Fibonacci_Solution2(unsigned n)
{
      
     int arr[2]={0,1};
     if(n<2) return arr[n];
   
      long long  FibN=0,FibNMinusOne=1,FibNMinusTwo=0;  
     for(int i=2;i<=n;i++)
       {
          FibN=FibNMinusOne+FibNMinusTwo;
          FibNMinusTwo=FibNMinusOne;
          FibNMinusOne=FibN;
       }
 return FibN;       

}

void test()
{
    int n;
    cout <<" please input the number n:"<<endl;
    cin >> n;
    cout <<" the result of the Fibonacci_Solution2 is: "<<Fibonacci_Solution2(n)<<endl;
    cout <<" the result of the Fibonacci_Solution1 is: "<<Fibonacci_Solution1(n)<<endl;
   

}

void test2(){

 int n,m;
    cin>>n;
     
   while( n>0)
      { 
         cin >>m;
         cout <<Fibonacci_Solution2(m)<<endl;
           n--;        
        }


}
int main()
{
// test();
 test2();
return 0;
}
