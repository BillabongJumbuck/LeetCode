//
// Created by QinJM on 25-6-13.
//

#ifndef LEETCODE_1116_H
#define LEETCODE_1116_H

#include <semaphore.h>
#include <functional>
using namespace std;
class ZeroEvenOdd {
private:
    int n;
    sem_t zero_sem;
    sem_t even_sem;
    sem_t odd_sem;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&zero_sem, 0, 1);
        sem_init(&odd_sem, 0, 0);
        sem_init(&even_sem, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=1;i<=n;i++) {
            sem_wait(&zero_sem);
            printNumber(0);
            if ((i & 1) == 1) {
                sem_post(&odd_sem);
            } else {
                sem_post(&even_sem);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=2;i<=n;i+=2) {
            sem_wait(&even_sem);
            printNumber(i);
            sem_post(&zero_sem);
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=1;i<=n;i+=2) {
            sem_wait(&odd_sem);
            printNumber(i);
            sem_post(&zero_sem);
        }
    }
};
#endif //LEETCODE_1116_H
