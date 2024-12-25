//
// Created by QinJM on 2024/1/6.
//

#ifndef LEETCODE_2807_H
#define LEETCODE_2807_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
private:
    int gcd(int x, int y){
        int z = y;
        while(x%y != 0){
            z = x % y;
            x = y;
            y = z;
        }
        return z;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode *ret = head;
        ListNode *tmp = head->next;
        while(head && tmp){
            ListNode* node = new ListNode(gcd(head->val, tmp->val));
            head->next = node;
            node->next = tmp;
            head = tmp;
            tmp = head->next;
        }
        return ret;
    }
};
#endif //LEETCODE_2807_H
