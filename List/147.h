//
// Created by QinJM on 2023/11/17.
//

#ifndef LEETCODE_147_H
#define LEETCODE_147_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode *dummy = new ListNode(0, head);
        ListNode *now = head->next;
        ListNode *tmp;
        head->next = nullptr;
        while(now){
            tmp = now->next;
            now->next = nullptr;
            ListNode* dummytmp = dummy;
            while(dummytmp->next && dummytmp->next->val < now->val)
                dummytmp = dummytmp->next;
            now->next = dummytmp->next;
            dummytmp->next = now;
            now = tmp;
        }
        tmp = dummy;
        dummy = dummy->next;
        delete tmp;
        return dummy;
    }
};
#endif //LEETCODE_147_H
