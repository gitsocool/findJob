#include <iostream>

#include <pthread.h>

using std::cin;
using std::cout;
using std::endl;

#define NUM_THREADS 5

void* say_hello(void* args)
{
    cout << "Hello Runoob！www" << endl;
}

int main()
{

    pthread_t tids[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; ++i)
    {
        cout << "make thread!!!"<< endl;
        int ret = pthread_create(&tids[i], NULL, say_hello, NULL);
        if (ret != 0)
        {
           cout << "pthread_create error: error_code=" << ret << endl;
        }
    }
      cout << "over thread!!!"<< endl;

    pthread_exit(NULL);
     
    cout <<"real to over thread"<<endl;
}
