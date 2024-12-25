//
// Created by QinJM on 2023/10/1.
//

#ifndef LEETCODE_237_H
#define LEETCODE_237_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *temp = node;
        while(temp->next->next){
            temp->val = temp->next->val;
            temp = temp -> next;
        }
        temp->val = temp->next->val;
        temp -> next = nullptr;
    }
};
#endif //LEETCODE_237_H
