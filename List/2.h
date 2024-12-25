//
// Created by QinJM on 2023/10/3.
//

#ifndef LEETCODE_2_H
#define LEETCODE_2_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* L = new ListNode();
        ListNode* head = L;
        if(l1 && l2){
            ListNode* tmp = (l1->val+l2->val, nullptr);
            L->next = tmp;
            L = L->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1){
            L->next = l1;
        }else{
            L->next = l2;
        }
        head = head->next;
        L = head;
        while(L){
            if(L->val >= 10){
                L->val-=10;
                if(L->next)
                    ++L->next->val;
                else{
                    ListNode* tmp = (1, nullptr);
                    L->next = tmp;
                }
            }
            L= L->next;
        }
        return L;
    }
};
#endif //LEETCODE_2_H
