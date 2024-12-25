//
// Created by QinJM on 2023/10/8.
//

#ifndef LEETCODE_82_H
#define LEETCODE_82_H
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
        if(head == nullptr)
            return head;
        ListNode *dummy = new ListNode(0,head);
        head = dummy;
        int val;
        ListNode *tmp;
        while(head->next && head->next->next){
            if(head->next->val == head->next->next->val){
                val = head->next->val;
                while(head->next->val == val){
                    tmp = head->next;
                    head->next = tmp->next;
                    delete tmp;
                    if(head->next == nullptr)
                        break;
                }
            }else{
                head = head->next;
            }
        }
        return dummy->next;
    }
};
#endif //LEETCODE_82_H
