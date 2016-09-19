#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
int toCountZhiShu(int sum)
{
  int count=0;
   vector<int>  vec; 
  for(int i=2;i<sum;i++) 
    {  bool isPrime=true;
       for(int j=2;j<i;j++)
          if(i%j==0) 
            {  
                isPrime=false;
                 break;
               }
       if(isPrime)  
         vec.push_back(i);
     }
   if(!vec.empty()){
    for(decltype(vec.size()) i=0;i!=vec.size()-1;i++)
        for(decltype(vec.size()) j=i;j!=vec.size();j++)
            if(vec[i]+vec[j]==sum) 
                     { cout<<vec[i]<<"+"<<vec[j]<<"\t";
                        ++ count;
                     }
   }
   return count;
}



int main()
{ 
  int sum;
  cout << " please inout an interger number!"<<endl;
 while( cin >>sum)
  cout<<toCountZhiShu(sum)<<endl;
return 0;
}
