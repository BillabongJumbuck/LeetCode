//
// Created by QinJM on 2023/9/26.
//

#ifndef LEETCODE_24_H
#define LEETCODE_24_H


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == nullptr)
            return nullptr;
        if(head->next == nullptr)
            return head;
        ListNode *tmp = head;
        head = head->next;
        tmp->next = head->next;
        head->next = tmp;
        tmp->next = swapPairs(tmp->next);
        return head;
    }
};

#endif //LEETCODE_24_H
