//
// Created by QinJM on 2023/11/28.
//

#ifndef LEETCODE_1670_H
#define LEETCODE_1670_H
struct myList {
    int val;
    myList *prev;
    myList *next;
    myList(){ val = 0; prev = nullptr; next = nullptr;}
    myList(int x){ val = x; prev = nullptr; next = nullptr;}
};
class FrontMiddleBackQueue {
private:
    myList *dummy;
    myList *tail;
    int size;
public:
    FrontMiddleBackQueue() {
        dummy = new myList(0);
        tail = dummy;
        size = 0;
    }

    void pushFront(int val) {
        myList *tmp = new myList(val);
        tmp->prev = dummy;
        tmp->next = dummy->next;
        dummy->next = tmp;
        if(size == 0){
            tail = tmp;
        }else{
            tmp->next->prev = tmp;
        }
        size++;
    }

    void pushMiddle(int val) {
        if(size==0 || size==1){
            pushFront(val);
            return;
        }
        int index = size/2;
        myList *position = dummy;
        while(index>0){
            position = position->next;
            index--;
        }
        myList *tmp = new myList(val);
        tmp->next = position->next;
        position->next->prev = tmp;
        position->next = tmp;
        tmp->prev = position;
        size++;
    }

    void pushBack(int val) {
        myList *tmp = new myList(val);
        tail->next = tmp;
        tmp->prev = tail;
        tail = tail->next;
        size++;
    }

    int popFront() {
        if(size == 0)
            return -1;
        size--;
        myList *tmp = dummy->next;
        int ret = tmp->val;
        dummy->next = tmp->next;
        if(size == 0){
            tail = dummy;
        }else{
            tmp->next->prev = dummy;
        }
        delete tmp;
        return ret;
    }

    int popMiddle() {
        if(size == 0)
            return -1;
        int ret;
        if(size == 1 || size == 2){
            ret = popFront();
            return ret;
        }
        int index = (size+1)/2;
        myList *position = dummy;
        while(index>0){
            position = position->next;
            index--;
        }
        ret = position->val;
        position->prev->next = position->next;
        position->next->prev = position->prev;
        delete position;
        size--;
        return ret;
    }

    int popBack() {
        if(size == 0)
            return -1;
        size--;
        myList *tmp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        int ret = tmp->val;
        delete tmp;
        return ret;
    }
};
#endif //LEETCODE_1670_H
