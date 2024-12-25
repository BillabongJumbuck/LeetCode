//
// Created by QinJM on 2023/11/1.
//

#ifndef LEETCODE_622_H
#define LEETCODE_622_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class MyCircularQueue {
private:
    int capacity;
    int size;
    ListNode *front;
    ListNode *rear;
public:
    MyCircularQueue(int k) {
        capacity = k;
        size = 0;
        front = new ListNode(0, nullptr);
        rear = front;
    }

    bool enQueue(int value) {
        if(isFull())
            return false;
        else{
            ListNode *tmp = new ListNode(value, nullptr);
            rear->next = tmp;
            rear = rear->next;
            ++size;
            return true;
        }
    }

    bool deQueue() {
        if(isEmpty())
            return false;
        else{
            ListNode *tmp = front;
            while(tmp->next->next)
                tmp = tmp->next;
            tmp->next = nullptr;
            delete rear;
            rear = tmp;
            --size;
            return true;
        }
    }

    int Front() {
        if(isEmpty())
            return -1;
        else
            front->next->val;
    }

    int Rear() {
        if(isEmpty())
            return -1;
        else
            return rear->val;
    }

    bool isEmpty(){
        return (size == 0);
    }

    bool isFull() {
        return (size == capacity);
    }
};

#endif //LEETCODE_622_H
