//
// Created by QinJM on 2023/11/5.
//

#ifndef LEETCODE_706_H
#define LEETCODE_706_H
#include <vector>
using namespace std;
struct MyListNode {
    int key;
    int value;
    MyListNode *next;
    MyListNode(int key, int value, MyListNode* next){
        this->key = key;
        this->value = value;
        this->next = next;
    }
};
class MyHashMap {
private:
    int TableSize;
    vector<MyListNode*> table;
    int HashFunc(int key){
        return key%TableSize;
    }
public:
    MyHashMap() {
        TableSize = 10009;
        MyListNode *dummy = new MyListNode(0,0, nullptr);
        table = vector<MyListNode*>(TableSize, dummy);
    }

    void put(int key, int value) {
        int position = HashFunc(key);
        MyListNode* tmp = table[position];
        while(tmp->next){
            if(tmp->next->key == key)
                return;
            tmp=tmp->next;
        }
        tmp->next = new MyListNode(key, value,nullptr);
    }

    int get(int key) {
        int position = HashFunc(key);
        MyListNode* tmp = table[position];
        while(tmp->next){
            if(tmp->next->key == key)
                break;
            else
                tmp = tmp->next;
        }
        return tmp->next->value;
    }

    void remove(int key) {
        int position = HashFunc(key);
        MyListNode* tmp = table[position];
        while(tmp->next){
            if(tmp->next->key == key){
                MyListNode *node = tmp;
                tmp->next = node->next;
                delete node;
            }
            else
                tmp = tmp->next;
        }
    }
};


#endif //LEETCODE_706_H
