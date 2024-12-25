//
// Created by QinJM on 2023/12/13.
//

#ifndef LEETCODE_23_H
#define LEETCODE_23_H
#include <vector>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    struct cpm{
        bool operator()(ListNode* a, ListNode* b) const {
            return b->val < a->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *dummy = new ListNode;
        ListNode *node = dummy;
        priority_queue<ListNode*, vector<ListNode*>, cpm> q;
        for(auto i : lists)
            if(i != nullptr) q.push(i);
        while(!q.empty()){
            ListNode *tmp = q.top(); q.pop();
            node->next = tmp;
            tmp = tmp->next;
            node = node->next;
            node->next = nullptr;
            if(tmp) q.push(tmp);
        }
        node = dummy->next;
        delete dummy;
        return node;
    }
};
#endif //LEETCODE_23_H
