//
// Created by QinJM on 2023/9/30.
//

#ifndef LEETCODE_206_H
#define LEETCODE_206_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode *flag = new ListNode(head->val, nullptr);
        head = head->next;
        while(head){
            ListNode *tmp = new ListNode(head->val,flag);
            flag = tmp;
            head =head->next;
        }
        return flag;
    }
};
#endif //LEETCODE_206_H
