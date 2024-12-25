//
// Created by QinJM on 2023/10/20.
//

#ifndef LEETCODE_445_H
#define LEETCODE_445_H
#include <stack>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return l1;
        else{
            if(l1 == nullptr)
                return l2;
            if(l2 == nullptr)
                return l1;
        }
        stack<ListNode*> add1;
        stack<ListNode*> add2;
        int cin = 0, a, b, sum;
        ListNode *tmp1 = l1;
        ListNode *tmp2 = l2;
        while(l1){
            add1.push(l1);
            l1 = l1->next;
        }
        while(l2){
            add2.push(l2);
            l2 = l2->next;
        }
        ListNode *dummy = new ListNode(0);
        ListNode *tmp = nullptr;
        while( !add1.empty() || !add2.empty()){
            a = b = 0;
            if(!add1.empty()){
                a = add1.top()->val;
                add1.pop();
            }
            if(!add2.empty()){
                b = add2.top()->val;
                add2.pop();
            }
            sum = a + b + cin;
            if(sum>=10){
                sum-=10;
                cin = 1;
            }else{
                cin = 0;
            }
            tmp = new ListNode(sum);
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        if(cin == 1){
            tmp = new ListNode(1);
            tmp->next = dummy->next;
            dummy->next = tmp;
        }
        tmp = dummy;
        dummy = dummy->next;
        delete tmp;
        return dummy;
    }
};

#endif //LEETCODE_445_H
