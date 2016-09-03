#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
int *  bubble_sort(int *a/* the same as int a[] */,int length){
     bool change=true;
     int temp;
    // auto length2= end(a)-begin(a); //error ,becausu a is a pointer

     for(int i=length-1;i>=1 && change;i--)
       {
         change=false;
         for(int j=0;j<i;j++)
            { 
              if(a[j]>a[j+1])   
                 {
                    temp=a[j];
                     a[j]=a[j+1];
                     a[j+1]=temp;
                 change=true;
                }
           }            
     }
 

     return a;
}

/*
void  bubble_sort22(int [] &a,int length){
        bool change=true;
       int temp;
       for(int i=length-1;i>=1 && change;i--)
         {
           change=false;
           for(int j=0;j<i;j++)
              {
                if(a[j]>a[j+1])
                   {
                      temp=a[j];
                      a[j]=a[i];
                      a[i]=temp;
                   change=true;
                  }
             }
       }
    
       for(int i=0;i<length;i++){
          cout << p[i]<<endl;
        }

 
     //  return a;
}
*/
int main(){

     cout <<" please input the size for the array:"<<endl;   
     int size;
     cin >> size;
      const  int rr=size;
     //constexpr int rr=size;//error
     int a[rr];
     int in,index=0;

     cout <<" please input numbers for the array:"<<endl; 
       while(cin >> in && index<size)
          a[index++]=in;
  // auto length= end(a)-begin(a);
    int length=size;
    int*  p= bubble_sort(a,length);
    cout <<"length of the array:"<<length<<endl;
    for(int i=0;i<length;i++){
      cout << p[i]<<endl;
     }

return 0;
}
