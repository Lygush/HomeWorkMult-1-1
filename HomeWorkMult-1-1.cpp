#include <iostream>
#include <thread>
#include <chrono>

void queue(int& counter) {
    const int max_queue{5};
    while (counter != max_queue) {
        counter++;
        std::cout << counter << " ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void window(int& counter) {
    while (counter != 0) {
        counter--;
        std::cout << counter << " ";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

int main() {
    int counter{0};
    std::thread t1(queue, std::ref(counter));
    std::thread t2(window, std::ref(counter));
    t1.join();
    t2.join();
}