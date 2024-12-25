//
// Created by QinJM on 2023/10/7.
//

#ifndef LEETCODE_19_H
#define LEETCODE_19_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *tail = head, *tmp = head;
        while(n>0){
            tail = tail->next;
            --n;
        }
        if(tail){while(tail->next){
                tail = tail->next;
                tmp = tmp->next;
            }
            tail = tmp->next;
            tmp->next = tail->next;
            delete tail;
        }else{
            head = head->next;
            delete tmp;
        }
        return head;
    }
};
#endif //LEETCODE_19_H
