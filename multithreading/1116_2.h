//
// Created by QinJM on 25-6-13.
//

#ifndef LEETCODE_1116_2_H
#define LEETCODE_1116_2_H

#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool zero_turn = true;
    bool odd_turn = false;
    bool even_turn = false;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 1;i <= n;i++){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){ return zero_turn;});
            printNumber(0);
            if ((i & 1) == 1) {
                odd_turn = true;
            } else {
                even_turn = true;
            }
            zero_turn = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i = 2;i <= n;i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){return even_turn;});
            printNumber(i);
            even_turn = false;
            zero_turn = true;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i = 1;i <= n;i += 2) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){return odd_turn;});
            printNumber(i);
            odd_turn = false;
            zero_turn = true;
            cv.notify_all();
        }
    }
};
#endif //LEETCODE_1116_2_H
