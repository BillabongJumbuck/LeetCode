//
// Created by QinJM on 2023/10/2.
//

#ifndef LEETCODE_234_H
#define LEETCODE_234_H
#include<vector>
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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        for(int i = 0;i<=(v.size()/2);++i){
            if(v[i] != v[v.size()-1-i])
                return false;
        }
        return true;
    }
};
#endif //LEETCODE_234_H
