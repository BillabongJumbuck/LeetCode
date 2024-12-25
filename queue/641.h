//
// Created by QinJM on 2023/11/2.
//

#ifndef LEETCODE_641_H
#define LEETCODE_641_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class MyCircularDeque {
private:
    int size;
    int capacity;
    ListNode* front;
    ListNode* rear;
public:
    MyCircularDeque(int k) {
        front = new ListNode(0);
        rear = front;
        size = 0;
        capacity = k;
    }

    bool insertFront(int value) {
        if(isFull())
            return false;
        else{
            ListNode *tmp = new ListNode(value);
            tmp->next =  front->next;
            front->next = tmp;
            if(size == 0)
                rear = tmp;
            ++size;
            return true;
        }

    }

    bool insertLast(int value) {
        if(isFull())
            return false;
        else{
            ListNode *tmp = new ListNode(value, nullptr);
            rear->next = tmp;
            rear = rear->next;
            size++;
            return true;
        }
    }

    bool deleteFront() {
        if(isEmpty())
            return false;
        else{
            ListNode *tmp = front->next;
            front->next = tmp->next;
            delete tmp;
            --size;
            if(isEmpty())
                rear = front;
            return true;
        }
    }

    bool deleteLast() {
        if(isEmpty())
            return false;
        else{
            ListNode *tmp = front;
            while(tmp->next->next)
                tmp = tmp->next;
            delete rear;
            rear = tmp;
            rear->next = nullptr;
            --size;
            return true;
        }
    }

    int getFront() {
        if(isEmpty())
            return -1;
        else
            return front->next->val;
    }

    int getRear() {
        if(isEmpty())
            return -1;
        else
            return rear->val;
    }

    bool isEmpty() {
        return (size == 0);
    }

    bool isFull() {
        return (size == capacity);
    }
};

#endif //LEETCODE_641_H
