#include<iostream>
#include<stdlib.h>
//#include<cstdlib>
#include<exception>
#include<stdexcept>
#include<time.h>
using std::cin;
using std::cout;
using std::endl;
int RandomInRange(int low,int high)
{
    if(low<high)
     {
       srand(time(NULL));
       return  rand()%(high-low+1)+low;
     }
    return 0;
}

int Partition(int *arr,int low,int high){
    if(arr==NULL)   
       {
            std::runtime_error ex(" data not legal!");
           throw std::exception(ex);          
        }
   //  int index=RandomInRange(low,high);
    
     int a=arr[low];
     int pivotkey=arr[low];
     while(low <high)
    {
        while(low < high && arr[high]>=pivotkey ) high--;
            arr[low]=arr[high];
     
         while(low < high && arr[low]<= pivotkey) low++;
            arr[high]=arr[low];

         
    }          
   arr[low]=a;
      
 return low;
}

void QSort(int *arr,int low,int high){
   
    if(low<high) 
     {
      int  pivotloc= Partition(arr,low,high);
      QSort(arr,low,pivotloc-1);
      QSort(arr,pivotloc+1,high);
       }
    
}
void test1()
{ 
   cout<<"---------test1----------" <<endl;
   int n;   
    cout <<" please input the size for the arr:"<<endl;
    cin>>n;
    int arr[n],in;
    auto p=arr;

    cout <<" please input the datas for the arr:"<<endl;
    while(cin>>in) 
       {
        *p=in;
         p++;
       }    
 try{
   QSort(arr,0,n-1);
     
   for(auto i:arr)
     cout <<i<<" ";
      cout<<endl;
   
   }catch(std::exception & e){
        cout<<e.what()<<endl;
          }
}
 
void test2()
{
  cout<<"---------test2----------" <<endl;
 try{
   QSort(NULL,0,1);
     
   
   }catch(std::exception & e){
        cout<<e.what()<<endl;
          }
}
int main(){
 test1();    
 test2();
   return 0;
}
