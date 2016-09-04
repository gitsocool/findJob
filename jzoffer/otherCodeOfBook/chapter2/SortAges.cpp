#include<iostream>
#include<cstdlib>
#include<exception>
using std::cin;
using std::cout;
using std::endl;
using std::exception;
using std::begin;
using std::end;
//#define oldAge 99

int*  SortAges(int ages[],int length)
{
     if(ages==NULL) return NULL;
   
       int oldAge=99; 
       int timesOfAge[oldAge+1];
        
       for(int i=0;i<oldAge+1;i++){
               timesOfAge[i]=0;
           } 

        for(int i=0;i<length;i++)
         {
            // int age=ages[i];          
               //  throw new exeption(" age out of range :") ;
            timesOfAge[ ages[i] ]++ ;                    
         }
     
       int index=0;
       for(int i=0;i<=oldAge;i++)
          for(int j=0;j<timesOfAge[i];j++)
               ages[index++]=i;
 return ages; 
}

void test()
{
    int n,in;
    cout<<" please input the size for ages array: "<<endl;
    cin >> n;
   int arr[n],index=0;
    cout <<" please inout the ages data :"<<endl;
     while( cin >> in && index<n)
          arr[index++]=in;
 
       // auto p=SortAges(arr,n);
  
       auto p=arr; 
      //auto pend=end(arr);
       SortAges(arr,n);

   for(int j=0;j<n;j++)
       cout<<*p++<<" ";
        cout <<endl;
 


}

int main()
{
  test();
 // int arr[]={1,2,3,45,6,87};
 //  auto p1=begin(arr),p2=end(arr);

   // for(;p1!=p2;p1++)cout <<*p1<<endl;
 
    
  return 0;
}
