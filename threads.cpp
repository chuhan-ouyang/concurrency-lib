#include <thread>
#include <string>
#include <iostream>

void hello(const std::string& to, int& counter) {
    ++counter;
    std::cout << "Hello, " << to << std::endl;
}

int main() {
    int counter = 0;

    // creating threads using function pointers and function parameters
    std::thread t1(hello, "c++", std::ref(counter));
    std::thread t2(hello, "programs", std::ref(counter));

    // creating threads using lambdas
    std::thread t3([] (std::string name) {
        std::cout << "Hello World! " << name << std::endl;
    }, "C++");

    // joining before exiting main
    t1.join();
    t2.join();
    t3.join();

    std::cout << "After threads, counter= " << counter << std::endl;
    return 0;
}