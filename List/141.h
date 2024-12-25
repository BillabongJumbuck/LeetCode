//
// Created by QinJM on 2023/9/27.
//

#ifndef LEETCODE_141_H
#define LEETCODE_141_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head){
            ListNode *L = head;
            while(L->next){
                if(find(head,L->next, L)){
                    return true;
                }
                L = L->next;
            }
        }
        return false;
    }
    bool find(ListNode *L, ListNode *X, ListNode *Y){
        while(L){
            if( L == X)
                return true;
            if(L == Y)
                break;
            L=L->next;
        }
        return false;
    }
};
#endif //LEETCODE_141_H
