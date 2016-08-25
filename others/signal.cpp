#include <iostream>
#include <csignal>
#include "pthread.h"
using namespace std;

void signalHandler( int signum )
{
    cout << "Interrupt signal (" << signum << ") received.\n";


   exit(signum);  

}

int main ()
{

    signal(SIGINT, signalHandler);  

    while(1){
       cout << "Going to sleep...." << endl;
       sleep("1");
    }

    return 0;
}
