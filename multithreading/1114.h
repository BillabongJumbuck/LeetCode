//
// Created by QinJM on 2024/4/3.
//

#ifndef LEETCODE_1114_H
#define LEETCODE_1114_H

#include <functional>
#include <semaphore.h>
using namespace std;
class Foo {
private:
    sem_t first_done;
    sem_t second_done;
    sem_t third_done;
public:
    Foo() {
        sem_init(&first_done, 0, 0);
        sem_init(&second_done, 0, 0);
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&first_done);
    }

    void second(function<void()> printSecond) {
        sem_wait(&first_done);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&second_done);
    }

    void third(function<void()> printThird) {
        sem_wait(&second_done);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
#endif //LEETCODE_1114_H
