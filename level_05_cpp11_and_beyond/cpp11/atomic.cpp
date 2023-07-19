// https://en.cppreference.com/w/cpp/atomic/atomic

#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> counter(0);

void incrementCounter()
{
    for (int i = 0; i < 10000; ++i)
    {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

int main()
{
    std::thread thread1(incrementCounter);
    std::thread thread2(incrementCounter);

    thread1.join();
    thread2.join();

    std::cout << "Counter value: " << counter << std::endl;

    return 0;
}
