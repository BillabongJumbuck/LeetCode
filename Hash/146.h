//
// Created by QinJM on 2023/11/20.
//

#ifndef LEETCODE_146_H
#define LEETCODE_146_H
#include <list>
using namespace std;
struct myList{
    int key;
    int value;
    myList *prev;
    myList *next;
    myList(int key, int value){
        this->key = key;
        this->value = value;
        this->prev = this->next = nullptr;
    }
};
class LRUCache {
private:
    myList *head = nullptr;
    myList *tail = nullptr;
    int capacity;
    int size;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
    }

    int get(int key) {
        int ret = -1;
        myList *tmp = head;
        while(tmp){
            if(tmp->key == key){
                ret = tmp->key;
                if(tmp != head){
                    myList *tmpprev = tmp->prev;
                    tmpprev->next = tmp->next;
                    tmp->next = head;
                    tmp->prev = nullptr;
                    head = tmp;
                }
                break;
            }else{
                tmp = tmp->next;
            }
        }
        return ret;
    }

    void put(int key, int value) {
        if(head == nullptr){
                head = new myList(key, value);
                tail = head;
                ++size;
                return;
        }
        myList *tmp = head;
        while(tmp){
            if(tmp->key == key){
                break;
            }else{
                tmp = tmp->next;
            }
        }
        if(tmp == head){
            tmp->value = value;
        }else if(tmp == nullptr){
            tmp = new myList(key, value);
            tmp->prev = nullptr;
            tmp->next = head;
            head = tmp;
        }else if(tmp != head){
            myList *tmpprev = tmp->prev;
            tmpprev->next = tmp->next;
            if(tmp == tail)
                tail = tmpprev;
            tmp->value = value;
            tmp->next = head;
            tmp->prev = nullptr;
            head = tmp;
        }
        ++size;
        if(size>capacity){
            tmp = tail;
            tail = tail->prev;
            delete tmp;
        }
    }
};

#endif //LEETCODE_146_H
