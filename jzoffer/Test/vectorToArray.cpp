#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
int main(){
   vector<int>  pre={1,2,3};
    int arr[pre.size()];
   
   for(decltype(pre.size()) i=0;i!=pre.size();i++)
            arr[i]=pre[i];
        
   for(auto a:arr)
     cout<<a<<endl;     
 
return 0;

}
