//
// Created by QinJM on 2023/10/3.
//

#ifndef LEETCODE_876_H
#define LEETCODE_876_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        int size = 0;
        ListNode *tmp = head;
        while(tmp){
            ++size;
            tmp = tmp->next;
        }
        int middle = size/2;
        while(middle!=0){
            head = head->next;
            --middle;
        }
        return head;
    }
};
#endif //LEETCODE_876_H
