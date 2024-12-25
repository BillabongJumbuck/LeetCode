//
// Created by QinJM on 2024/4/3.
//

#ifndef LEETCODE_1114_H
#define LEETCODE_1114_H

#include <functional>

using namespace std;
class Foo {
private:
    int a;
    int b;
public:
    Foo() {
        a = 0;
        b = 0;
    }

    void first(function<void()> printFirst) {
        a++;
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
    }

    void second(function<void()> printSecond) {
        while(a!=1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        a--;
        b++;
    }

    void third(function<void()> printThird) {
        while(b!=1);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        b--;
    }
};
#endif //LEETCODE_1114_H
