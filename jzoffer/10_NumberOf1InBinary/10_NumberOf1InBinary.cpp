#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int NumberOf1_1(int n)
{
   int count=0;
   unsigned int flag=1;
   while(flag)
    {
      if( n & flag )
         ++count;
      flag= flag<<1;
    }
     return count;
}

int NumberOf1_2(int n)
{
   int count=0; 
   while(n)
   {
      n=(n-1)&n;
     count++;
   }
   return count;  
}

void testForPositive()
{
  
   int n;
  cout<<" please input positive number :"<<endl;
  while(cin >> n)
     cout << NumberOf1_2(n)<<endl;

 // cout<<NumberOf1_2(0x7fffffff)<<endl;
 // cout<<NumberOf1_2(0x80000000)<<endl;
 // cout<<NumberOf1_2(0xffffffff)<<endl;
 
}
void testForNegative()
{
 int n; 
  cout<<" now ,if you want to try the nagative number,please input  Hexadecimal  number:"<<endl;
     while(cin >> std::hex >>n )
     cout <<NumberOf1_2(n)<<endl;

}

int main()
{
testForPositive();
// testForNegative();
 return 0;
}
