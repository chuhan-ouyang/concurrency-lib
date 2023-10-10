#include <algorithm>
#include <vector>
#include <mutex>
#include <thread>
#include <iostream>

std::vector<int> my_vec;
std::mutex my_mutex;

void add_to_list(int new_value) {
    std::scoped_lock<std::mutex> lck(my_mutex);
    my_vec.push_back(new_value);
}

void list_contains(int value_to_find) {
    std::scoped_lock<std::mutex> lck(my_mutex);
    if (std::find(my_vec.begin(), my_vec.end(), value_to_find) != my_vec.end()) {
        std::cout << "my_vec contains: " << value_to_find << std::endl;
    } else {
        std::cout << "my_vec does not contain: " << value_to_find << std::endl;
    }
}

int main() {
    std::thread t2(list_contains, 2);
    std::thread t1(add_to_list, 2);

    t2.join();
    t1.join();
    return 0;
}