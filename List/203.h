//
// Created by QinJM on 2023/9/27.
//

#ifndef LEETCODE_203_H
#define LEETCODE_203_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tmp = new ListNode(-1,head);
        ListNode *L =tmp;
        while(tmp->next){
            if(tmp->next->val == val){
                ListNode *d =tmp->next;
                tmp->next = d->next;
                delete d;
            }else{
                tmp = tmp->next;
            }
        }
        return L->next;
    }
};
#endif //LEETCODE_203_H
