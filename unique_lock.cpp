#include <algorithm>
#include <vector>
#include <mutex>
#include <thread>
#include <iostream>

std::mutex mtx;
int global_val = 100;

void print_block() {
    std::unique_lock<std::mutex> lck(mtx);
    std::cout << global_val << std::endl;
}

int main() {
    std::thread th1(print_block);
    std::thread th2(print_block);
    th1.join();
    th2.join();
    return 0;
}