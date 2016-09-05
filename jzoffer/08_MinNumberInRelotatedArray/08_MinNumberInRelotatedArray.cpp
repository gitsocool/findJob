#include<iostream>
#include<exception>
using std::cin;
using std::cout;
using std::endl;
using std::exception;

int SearchSeqForMin(int *arr,int index1,int index2);

int Min(int *arr,int length)
{
   if(arr==NULL || length<=0)
      throw new std::exception();
   
     int index=0;
      
   
  
}

int SearchSeqForMin(int *arr,int index1,int index2)
{
     int min=arr[index1];
     
     for(int i=index+1;i<=index2;i++)
      { 
          if(min>arr[i])
             min=arr[i];
      }
   return min;

}





int main()
{
return 0;
}
