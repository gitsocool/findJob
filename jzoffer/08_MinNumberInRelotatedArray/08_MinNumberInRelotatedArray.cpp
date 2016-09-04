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
   
     int index1=0,index2=length-1;
     int  mid=index1; 
    
   if(arr[index1]==arr[index2] && arr[mid]==arr[index1] )     
            return SearchSeqForMin(arr,index1,index2);
 
   
    while(index1<index2)
    {
       if(index2-index=1)
             break;
  
       if(arr[mid]>=arr[index1])
            index1=mid;
        if(arr[mid]<=arr[index2])
           index2=mid;
      mid=(index1+index2)/2;        
    }

   return arr[mid];
  
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
