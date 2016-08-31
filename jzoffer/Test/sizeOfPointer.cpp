#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
int main(){
   char a='w';
   int b=5;
   string s="jygweyu geygyug";
  
    char *pa=&a;
    int *pb=&b;
    auto *ps=&s;

   cout<<" the sizeof pointer to char :"<<sizeof(pa)<<endl;
   cout<<" the sizeof pointer to int :"<<sizeof(pb)<<endl;
   cout<<" the sizeof pointer to string :"<<sizeof(ps)<<endl;
return 0;
}
