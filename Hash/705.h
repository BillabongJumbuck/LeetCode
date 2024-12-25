//
// Created by QinJM on 2023/11/5.
//

#ifndef LEETCODE_705_H
#define LEETCODE_705_H
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 分离链接法
//class MyHashSet {
//    int TableSize;
//    vector<ListNode*> table;
//    int HashFunc(int key){
//        return key%TableSize;
//    }
//public:
//    MyHashSet() {
//        TableSize = 10009;
//        ListNode* dummy = new ListNode(0, nullptr);
//        table = vector<ListNode*>(TableSize, dummy);
//    }
//
//    void add(int key) {
//        int position = HashFunc(key);
//        ListNode* tmp = table[position];
//        while(tmp->next){
//            if(tmp->next->val == key)
//                return;
//            tmp=tmp->next;
//        }
//        tmp->next = new ListNode(key, nullptr);
//    }
//
//    void remove(int key) {
//        int position = HashFunc(key);
//        ListNode* tmp = table[position];
//        while(tmp->next){
//            if(tmp->next->val == key){
//                ListNode *node = tmp->next;
//                tmp->next = node->next;
//                delete node;
//            }
//            tmp=tmp->next;
//        }
//    }
//
//    bool contains(int key) {
//        int position = HashFunc(key);
//        ListNode* tmp = table[position];
//        while(tmp->next){
//            if(tmp->next->val == key)
//                return true;
//            tmp=tmp->next;
//        }
//        return false;
//    }
//};

// 开放定址法
#endif //LEETCODE_705_H
