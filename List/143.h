//
// Created by QinJM on 2023/10/12.
//

#ifndef LEETCODE_143_H
#define LEETCODE_143_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *tail;
        while(head && head->next){
            tail = head;
            while(tail->next && tail->next->next)
                tail = tail->next;
            if(head == tail)
                return;

            head->next = tail->next->next;
            tail->next = nullptr;
            head = head->next->next;
        }
    }
};
#endif //LEETCODE_143_H
