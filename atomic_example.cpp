#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> global_sum(0);

void sumNumbers(int increment) {
    for (int i = 0; i < increment; ++i) {
        global_sum += 1;
    }
}

int main() {
    std::thread t1(sumNumbers, 100000);
    std::thread t2(sumNumbers, 100000);
    std::thread t3(sumNumbers, 100000);

    t1.join();
    t2.join();
    t3.join();

    std::cout << global_sum.load() << std::endl;
    return 0;
}