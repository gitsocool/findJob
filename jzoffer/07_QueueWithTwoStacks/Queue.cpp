#include<iostream>
#include<stack>
#include<exception>
#include <stdexcept>
using std::stack;
using std::cin;
using std::cout;
using std::endl;
template <typename T> class CQueue
{
   public :
            CQueue();
            ~ CQueue();
           
       void appendTail(const T& element);
        T  deleteHead();
       bool empty();
       int size();
   private:
    stack<T> stack1;
    stack<T> stack2;
              
        
};

template<typename T>
CQueue<T>::CQueue()
{
}

template<typename T>
CQueue<T>::~CQueue()
{
} 

template<typename T>
void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);  
}

template <typename T>
T CQueue<T>::deleteHead()
{
   if(stack2.size()<=0)
   {
         while(stack1.size()>0)
         {
                 T data=stack1.top();
                 stack1.pop();
                 stack2.push(data);         
         }
   
   }

   if(stack2.empty()) {
        std::logic_error ex(" the queue is empty!");  
       throw std::exception(ex);
  }  
   T head = stack2.top();
   stack2.pop();
   return head;  

}

template <typename T>
bool CQueue<T>::empty(){
    return (stack1.empty() && stack2.empty());
}
template <typename T>
int CQueue<T>::size()
 {
    return stack1.size()+stack2.size();
 }

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
        cout<<ex.what();
     } 
  }
 
   // to meet the exception on purpose 
    try{
      cout << queue.deleteHead()<<endl;
      }
      catch(std::exception & ex){
          cout<<ex.what()<<endl;
       }

  return 0;
}

