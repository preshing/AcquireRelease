#include <thread>
#include <atomic>
#include <stdio.h>
#include "randomdelay.h"

using namespace std;

atomic<int> flag;
int sharedValue = 0;

RandomDelay randomDelay1(1, 60101);
RandomDelay randomDelay2(2, 65535);

void IncrementSharedValue10000000Times(RandomDelay& randomDelay)
{
    int count = 0;
    while (count < 10000000)
    {
        randomDelay.doBusyWork();
        int expected = 0;
        if (flag.compare_exchange_strong(expected, 1, memory_order_relaxed))
        {
            // Lock was successful
            sharedValue++;
            flag.store(0, memory_order_relaxed);
            count++;
        }
    }
}

void Thread2Func()
{
    IncrementSharedValue10000000Times(randomDelay2);
}

int main(int argc, char* argv[])
{
    printf("is_lock_free: %s\n", flag.is_lock_free() ? "true" : "false");
    
    for (;;) {
        sharedValue = 0;
        thread thread2(Thread2Func);
        IncrementSharedValue10000000Times(randomDelay1);
        thread2.join();
        printf("sharedValue=%d\n", sharedValue);
    }
    
    return 0;
}

