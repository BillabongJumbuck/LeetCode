//
// Created by QinJM on 2023/10/9.
//

#ifndef LEETCODE_86_H
#define LEETCODE_86_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next){
            return head;
        }
        ListNode *dummy = new ListNode(-101,head);
        ListNode *prev, *tmp;
        head = dummy;
        while(head->next){
            if(head->next->val >= x){
                break;
            }
            head = head->next;
        }
        prev = head;
        while(head->next){
            if(head->next->val < x){
                tmp = head->next;
                head->next = tmp->next;
                tmp->next = prev->next;
                prev->next = tmp;
                prev = prev->next;
            }
            else{
                head = head->next;
            }
        }
        tmp = dummy;
        dummy = dummy->next;
        delete tmp;
        return dummy;
    }
};

#endif //LEETCODE_86_H
