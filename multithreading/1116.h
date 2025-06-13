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
    int count;
    sem_t zero_sem;
    sem_t even_sem;
    sem_t odd_sem;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->count = 1;
        sem_init(&zero_sem, 0, 1);
        sem_init(&odd_sem, 0, 0);
        sem_init(&even_sem, 0, 0);
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(;;) {
            sem_wait(&zero_sem);
            if (count > n) {
                sem_post(&odd_sem);
                sem_post(&even_sem);
                break;
            }
            printNumber(0);
            if (count % 2 == 1) {
                sem_post(&odd_sem);
            } else {
                sem_post(&even_sem);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for(;;) {
            sem_wait(&even_sem);
            if (count > n) {
                sem_post(&zero_sem);
                break;
            }
            printNumber(count);
            count++;
            sem_post(&zero_sem);
        }
    }

    void odd(function<void(int)> printNumber) {
        for(;;) {
            sem_wait(&odd_sem);
            if (count > n) {
                sem_post(&zero_sem);
                break;
            }
            printNumber(count);
            count++;
            sem_post(&zero_sem);
        }
    }
};
#endif //LEETCODE_1116_H
