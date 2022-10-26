#include <thread>
#include <mutex>
#include <iostream>
#include <mutex>
using namespace std;

int main() {
    std::mutex mtx;
    mtx.lock();
    std::thread t1([&](){
        mtx.lock();
        mtx.unlock();
        cout << "hello 2" << endl;
    });

    cout << "hello 1" << endl;
    mtx.unlock();
    t1.join();
    return 0;
}