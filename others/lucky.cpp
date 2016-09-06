#include<iostream>
using namespace std;
bool isLucky(int n)
{
    int f=0,g=0;
     int n1=n,n2=n;
      while(n1>0)
     {
        f+=n1%10;
        n1=n1/10;   
     }
  //  f+=n1;
      
      while(n2>0)
      {
          g+=n%2;
          n2=n2/2;  
      }
    //  g+=n2;
      
      if(f==g) return true;
      else return false;
}

int main()
{
     int a;
     cin >> a;
      int  n;
     while(a>0){
     
        cin >> n;
        int num=0;
           for(int i=0;i<=n;i++)
           {
               if(isLucky(i)) ++num;
           }
     if(num>0){
           cout << num <<endl;
		  
     }
	 a--;
     } 
      
     return 0; 
      
}
