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
      
      while(n2>0)
      {
          g++;
          n2=(n2-1) & n2;
      
      /*  //next also can evaluate
          g+=n2%2;
          n2=n2/2; 
      */
      }
      
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
           for(int i=1;i<=n;i++)
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
