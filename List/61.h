//
// Created by QinJM on 2023/10/6.
//

#ifndef LEETCODE_61_H
#define LEETCODE_61_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k==0)
            return head;
        int n = 1;
        ListNode* iter = head;
        while(iter->next){
            iter = iter->next;
            ++n;
        }
        int add = n-k%n;
        if(add == n){
            return head;
        }
        iter->next = head;
        while(add--){
            iter = iter->next;
        }
        ListNode* ret = iter->next;
        iter->next = nullptr;
        return ret;
    }
//    ListNode* rotateRight(ListNode* head, int k) {
//        if(head == nullptr || head->next == nullptr)
//            return head;
//        int size = 0;
//        ListNode *tmp = head;
//        while(tmp){
//            tmp = tmp->next;
//            ++size;
//        }
//        tmp = head;
//        int count = k%size;
//        while(count>0){
//            --count;
//            head = moveOneToRight(head);
//        }
//        return head;
//    }
//    ListNode* moveOneToRight(ListNode *head){
//        ListNode *tmp = head;
//        while(tmp->next->next){
//            tmp=tmp->next;
//        }
//        ListNode *tmp2 = tmp->next;
//        tmp->next = nullptr;
//        tmp2->next = head;
//        return tmp2;
//    }
};
#endif //LEETCODE_61_H
