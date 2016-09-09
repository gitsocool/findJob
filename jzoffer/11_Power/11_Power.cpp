#include<iostream>
#include<math.h>
using std::cin;
using std::cout;
using std::endl;
bool equal(double num1,double num2);
double PowerWithUnsignedExponent(double base,unsigned int exponent);
double PowerWithUnsignedExponent2(double base,unsigned int exponent);

bool g_InvalidInput=false;


double Power(double base,int exponent)
{
   g_InvalidInput=false;
   if(equal(base,0.0) && exponent<0)
    {
       g_InvalidInput=true;
       return 0.0;
    }
    
   unsigned int absExponent;
  
    absExponent=abs(exponent);
/*
   if(exponent<0)
      absExponent=(unsigned int)( -exponent);
    else
      absExponent= (unsigned int)(exponent);
 */ 
   double result=PowerWithUnsignedExponent2(base,absExponent);
   
    if(exponent<0)
     result=1.0/result ;   
 
   return result;   
}

double PowerWithUnsignedExponent(double base,unsigned int exponent)
{    
     double result=1.0;
     for(int j=1;j<=exponent;j++)
          result*=base;

     return result;    
}

bool equal(double num1,double num2)
{
      
    // if( (num1-num2>-0.0000001) && (num1-num2<0.0000001))    
     if(abs(num1-num2)<0.0000001) 
       return true;
      else return false;
}

double PowerWithUnsignedExponent2(double base,unsigned int exponent)
{
     double arr[2]={0,base};
     if(exponent<2) return arr[exponent];

     double result=PowerWithUnsignedExponent2(base,exponent>>1);
     result*=result;
     
      if(exponent & 0x1 ==1)
       {
           result*=base;
       }

    return result;
}

void test()
{
   double base,result;
   int exponent;
   cout<<" please input the base:"<<endl;
   cin>>base;

   cout<<" please input the exponent:"<<endl;
   cin>>exponent;

   result=Power(base,exponent);
    if(g_InvalidInput) 
        cout <<" InvalidInput "<<endl;
    else
        cout<<" the result is : "<<result<<endl;

}
int main()
{
test();
return 0;
}
