//
// Created by QinJM on 2023/10/10.
//

#ifndef LEETCODE_92_H
#define LEETCODE_92_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr)
            return head;
        ListNode *dummy = new ListNode(0,head);
        head = dummy;
        int count = 1;
        ListNode *tmp = head, *leftNode, *rightNode, *prev;
        while(tmp){
            if(count == left)
                leftNode = tmp;
            if(count-1 == right){
                rightNode = tmp;
                break;
            }
            ++count;
            tmp = tmp->next;
        }
        prev = leftNode->next;
        head = prev->next;
        leftNode->next = rightNode;
        prev->next = rightNode->next;
        if(prev!= rightNode && head){
            while(head != rightNode){
                tmp = head->next;
                head->next = prev;
                prev = head;
                head = tmp;
            };
            head->next = prev;
        }
        tmp = dummy;
        dummy = dummy->next;
        delete tmp;
        return dummy;
    }
};
#endif //LEETCODE_92_H
