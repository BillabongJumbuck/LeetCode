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
    int count = 0;
    bool flag = true;
    bool zero_turn = true;
    bool odd_turn = false;
    bool even_turn = false;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){ return count >= n || zero_turn;});
            if (count >= n){
                cv.notify_all();
                break;
            }
            printNumber(0);
            if (flag){
                odd_turn = true;
            }else{
                even_turn = true;
            }
            flag = !flag;
            zero_turn = false;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){return count >= n || even_turn;});
            if (count >= n){
                cv.notify_all();
                break;
            }
            count ++;
            printNumber(count);
            even_turn = false;
            zero_turn = true;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (true){
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this](){return count >= n || odd_turn;});
            if (count >= n){
                cv.notify_all();
                break;
            }
            count ++;
            printNumber(count);
            odd_turn = false;
            zero_turn = true;
            cv.notify_all();
        }
    }
};
#endif //LEETCODE_1116_2_H
