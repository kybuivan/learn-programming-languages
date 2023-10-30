// https://en.cppreference.com/w/cpp/thread/packaged_task

#include <cmath>
#include <functional>
#include <future>
#include <iostream>
#include <thread>

// unique function to avoid disambiguating the std::pow overload set
int f(int x, int y)
{
    return static_cast<int>(std::pow(x, y)); // Explicitly convert double to int
}

void task_lambda()
{
    std::packaged_task<int(int, int)> task([](int a, int b) { return static_cast<int>(std::pow(a, b)); }); // Explicitly convert double to int
    std::future<int> result = task.get_future();

    task(2, 9);

    std::cout << "task_lambda:\t" << result.get() << '\n';
}

void task_bind()
{
    std::packaged_task<int()> task(std::bind(f, 2, 11));
    std::future<int> result = task.get_future();

    task();

    std::cout << "task_bind:\t" << result.get() << '\n';
}

void task_thread()
{
    std::packaged_task<int(int, int)> task(f);
    std::future<int> result = task.get_future();

    std::thread task_td(std::move(task), 2, 10);
    task_td.join();

    std::cout << "task_thread:\t" << result.get() << '\n';
}

int main()
{
    task_lambda();
    task_bind();
    task_thread();

    return 0;
}
