#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
   char a[1000];
   char b[1000];
  
     
   cin.getline(a,999);
  
   ofstream ofs;
   ofs.open("file.dat");
   ofs << a;
   ofs.close();

    ifstream ifs;
    ifs.open("file.dat");
    ifs >> b;
    ifs.close();
    cout <<b <<endl;

  


return 0;
}
