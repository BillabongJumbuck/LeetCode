//
// Created by QinJM on 2023/9/27.
//

#ifndef LEETCODE_83_H
#define LEETCODE_83_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head){
            while(head->next && (head->val == head->next->val)){
                ListNode *tmp = head->next;
                head->next = tmp->next;
                delete tmp;
            }
            head->next = deleteDuplicates(head->next);
            return head;
        }
        return nullptr;
    }
};
#endif //LEETCODE_83_H
