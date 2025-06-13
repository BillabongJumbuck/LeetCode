//
// Created by QinJM on 25-6-13.
//

#ifndef LEETCODE_1115_H
#define LEETCODE_1115_H

#include <semaphore.h>
#include <functional>
using namespace std;
class FooBar {
private:
    int n;
    sem_t printedFoo;
    sem_t printedBar;
public:
    FooBar(int n) {
        this->n = n;
        sem_init(&printedFoo, 0 ,0);
        sem_init(&printedBar, 0, 1);
    }

    void foo(function<void()> printFoo) {

        for (int i = 0; i < n; i++) {
            sem_wait(&printedBar);
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            sem_post(&printedFoo);
        }
    }

    void bar(function<void()> printBar) {

        for (int i = 0; i < n; i++) {
            sem_wait(&printedFoo);
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            sem_post(&printedBar);
        }
    }
};
#endif //LEETCODE_1115_H
