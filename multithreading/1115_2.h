//
// Created by QinJM on 25-6-13.
//

#ifndef LEETCODE_1115_2_H
#define LEETCODE_1115_2_H

#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool fooDone = false;
    bool barDone = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){return barDone;});
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            fooDone = true;
            barDone = false;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){return fooDone;});
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            barDone = true;
            fooDone = false;
            cv.notify_all();
        }
    }
};
#endif //LEETCODE_1115_2_H
