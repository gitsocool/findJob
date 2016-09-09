#include<iostream>
#include<cstdlib>
using std::cin;
using std::cout;
using std::endl;
void ReorderOddEvent_1(int *arr,unsigned int length)
{
   if(arr==NULL || length<0) return;
   int *pFront=arr;
   int *pTail=arr+length-1;     
   int temp;
   while(pFront<pTail)
   {   
     while(pFront<pTail &&  (*pFront & 0x1)!=0 ) ++pFront;
                
      while(pFront<pTail &&  (*pTail & 0x1) ==0) --pTail;             
    
       if(pFront<pTail)
        { temp=*pFront;
         *pFront=*pTail;
         *pTail=temp;      
        }
   }
     
}

//.........Another Way.................
bool isEven(int n);
void Reorder(int * arr,unsigned int length,bool (*pFunc)(int));
void ReorderOddEvent_2(int * arr,unsigned int length)
{
      Reorder(arr,length,isEven) ; 
}    
bool isEven(int n)
{
     return (n & 0x1)==0;
}

void Reorder(int * arr,unsigned int length,bool (*pFunc)(int))
{

   if(arr==NULL || length<0) return;
   int *pFront=arr;
   int *pTail=arr+length-1;     
   int temp;
   while(pFront<pTail)
   {   
     while(pFront<pTail &&  !pFunc(*pFront)) ++pFront;
                
      while(pFront<pTail &&  pFunc(*pTail)) --pTail;             
    
       if(pFront<pTail)
        { temp=*pFront;
         *pFront=*pTail;
         *pTail=temp;      
        }
   }

}



void forTest()
{ 
   int n;
    cout<<" please input the size for the array:"<<endl;
  while( cin >> n){
   int arr[n];
   auto p=arr,pEnd=arr+n-1;
   cout<<" plese input the elments for the array:"<<endl;
   for(int i=0;i!=n;i++)
        cin>>arr[i];
    //ReorderOddEvent_1(arr,n);
    ReorderOddEvent_2(arr,n);   
    cout<<" after Reorder:"<<endl;

      while(p<=pEnd)
         cout<<*p++<<"\t";
    cout<<endl;
 
    cout<<" please input the size for the array:"<<endl;
   }
}

int main()
{
forTest();
return 0;
} 
