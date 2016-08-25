#include <iostream>
#include <cstdlib>
#include <pthread.h>

using std::cin;
using std::cout;
using std::endl;


#define NUM_THREADS     5

void *PrintHello(void *threadid)
{  
//       int *p;
  //  p=threadid;
   long  tid = *(long*)threadid;
   cout << "Hello Runoob! 线程 ID, " << tid << endl;
   pthread_exit(NULL);
}

int main ()
{
   pthread_t threads[NUM_THREADS];
   int indexes[NUM_THREADS];
   int rc;
   long i;
   for( i=0; i < NUM_THREADS; i++ ){      
      cout << "main() : 创建线程, " << i << endl;
      indexes[i] = i;
    
      rc = pthread_create(&threads[i], NULL, 
                          PrintHello, (void *)&(indexes[i]));
      if (rc){
         cout << "Error:无法创建线程," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
