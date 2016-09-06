#include<iostream>
#include<exception>
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
int SearchSeqForMin(int *arr,int index1,int index2);

int Min(int *arr,int length)
{
   if(arr==NULL || length<=0)
      throw std::exception();
   
     int index1=0,index2=length-1;
     int  mid=index1; 
    
    while(arr[index1]>=arr[index2])
    {
      if(index2-index1==1)
         { mid=index2;  
           break;
          }
      mid=(index1+index2)/2; 
       
   if(arr[index1]==arr[index2] && arr[mid]==arr[index1] )     
            return SearchSeqForMin(arr,index1,index2);
       
   
      if(arr[mid]>=arr[index1])
            index1=mid;
       else 
           if(arr[mid]<=arr[index2])
             index2=mid;
    }

   return arr[mid];
  
}

int SearchSeqForMin(int *arr,int index1,int index2)
{
     int min=arr[index1];
     
     for(int i=index1+1;i<=index2;i++)
      { 
          if(min>arr[i])
             min=arr[i];
      }
   return min;

}


void test1()
{
 cout <<"-------test1----------"<<endl;
   int size;
   cout<<" please input the size for the array! "<<endl;
   cin >> size ;
   int arr[size],in,index=0;
   cout <<" please input the elements to initialize the array!"<<endl;
   while(cin >> in &&  index!=size)
       arr[index++]=in;
 try{
    int min=Min(arr,size);
    cout <<" the minest element is :"<< min <<endl; 
 } catch(std::exception & e)
   {
   cout <<e.what()<<endl;
    }
}

void test2()
{
       
   cout <<"-------test2----------"<<endl;
   int size;
   cout<<" please input the size for the array! "<<endl;
   cin >> size ;
   int arr[size],in,index=0;
   cout <<" please input the elements to initialize the array!"<<endl;
   while(cin >> in &&  index!=size)
       arr[index++]=in;
 
   cout <<" the minest element is :"<< SearchSeqForMin(arr,0,size-1) <<endl;

}
int main()
{
test1();
//test2();
return 0;
}
