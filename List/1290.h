//
// Created by QinJM on 2023/10/11.
//

#ifndef LEETCODE_1290_H
#define LEETCODE_1290_H
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num = 0, count = -1;
        func(head,count,num);
        return num;
    }
    void func(ListNode* node,int &count,int &num){
        if(node == nullptr)
            return ;
        func(node->next,count,num);
        count++;
        num += node->val << count;
    }
};
#endif //LEETCODE_1290_H
