#include <iostream>
         
using namespace std;
         
#define  OUTPUT(A) cout<<#A<<":"<<A<<endl;
         
int main()
{
    int a=1,b=2;
         
    OUTPUT(a);
    OUTPUT(b);
    OUTPUT(a+b);
         
    return 1;
}
