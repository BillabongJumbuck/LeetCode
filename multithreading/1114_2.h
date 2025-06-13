//
// Created by QinJM on 25-6-13.
//

#ifndef LEETCODE_1114_2_H
#define LEETCODE_1114_2_H

#include <functional>
#include <mutex>
#include <condition_variable>


using namespace std;
class Foo {
private:
    mutex mtx;
    condition_variable cv;
    bool first_done = false;
    bool second_done = false;
public:
    Foo() {

    }

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        first_done = true;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] () -> bool { return first_done;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        second_done = true;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this] () -> bool { return second_done;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
#endif //LEETCODE_1114_2_H
