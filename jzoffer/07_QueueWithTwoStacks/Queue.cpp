#include<stack>
using std::stack;
template <typename T> class CQueue{
   public :
            CQueue();
            ~ CQueue();
           
       void appendTail(const T& element);
        T  deleteHead();

   private:
    stack<T> stack1;
    stack<T> stack2;
              
        
};

int main(){

return 0;
}
