#include <algorithm>
#include <vector>
#include <mutex>
#include <thread>
#include <shared_mutex>
#include <iostream>

std::shared_mutex mtx;
int global_val = 100;

void print_block() {
    std::shared_lock<std::shared_mutex> lck(mtx);
    std::cout << global_val << std::endl;
}

int main() {
    std::thread t1(print_block);
    std::thread t2(print_block);
    t1.join();
    t2.join();
    return 0;
}