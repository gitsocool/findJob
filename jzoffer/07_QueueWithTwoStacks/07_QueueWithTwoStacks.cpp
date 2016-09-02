#include"./Queue.h"

int main(){
 CQueue<char> queue;
 char c; 
cout <<" please imout some data to the queue!"<<endl;
while(cin>>c){
 queue.appendTail(c);
  }
 
  while(!queue.empty()){
  try{
    cout << queue.deleteHead()<<endl;
    }
    catch(std::exception & ex){
        cerr<<ex.what();
     } 
  }

  try{
      cout << queue.deleteHead()<<endl;
      }
      catch(std::exception & ex){
          cout<<ex.what()<<endl;
       }

  return 0;
} 
