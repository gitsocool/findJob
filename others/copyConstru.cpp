#include <iostream>
using namespace std;
class CExample   
{  
private:  
 int a;  
  
public:  

 CExample(int b)  
 {   
	  cout<<"creat"<<endl;  
  a = b;  
 }  
  
 
 CExample(const CExample& C)  
 {  
  a = C.a;  
  cout<<"copy"<<endl;  
 }  
  
     void Show ()  
     {  
         cout<<a<<endl;  
     }

  ~CExample(){

        cout << "release" <<endl;
   }
  
};  
  

CExample g_Fun()  
{  
 CExample temp(0);  
 return temp;  
}  
  
int main()  
{  
 g_Fun();  
 return 0;  
}  
