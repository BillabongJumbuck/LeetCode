//
// Created by QinJM on 2023/10/10.
//

#ifndef LEETCODE_328_H
#define LEETCODE_328_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *tmp;
        ListNode *first = head, *second = head->next;
        while(second && second->next){
            tmp = second->next;
            second->next = tmp->next;
            tmp->next = first->next;
            first->next = tmp;
            first = first->next;
            second = second->next;
        }
        return head;
    }
};
#endif //LEETCODE_328_H
