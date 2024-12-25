//
// Created by QinJM on 2024/1/13.
//

#ifndef LEETCODE_2182_H
#define LEETCODE_2182_H
#include <string>
#include <vector>
using namespace std;
struct ListNode {
    char val;
    ListNode *next;
    ListNode() : val (' '), next(nullptr) {}
    ListNode(char x) : val(x), next(nullptr) {}
};
class Solution {
private:
    ListNode *insert(ListNode* head, char c){
        ListNode *node = head;
        while(node->next && node->next->val > c)
            node = node->next;
        if(node->val != c){
            ListNode *tmp = new ListNode(c);
            tmp->next = node->next;
            node->next = tmp;
        }
        return head;
    }
public:
    string repeatLimitedString(string s, int repeatLimit) {
        ListNode* dummy = new ListNode();
        for(const auto& c : s)
            dummy = insert(dummy, c);

        string ans;
        ListNode *head = dummy->next;
        int count = 0;
        while(head){
            if(head->val == '#'){
                head = head->next;
            }else if(count < repeatLimit || head->val != ans.back()){
                if(ans.empty() || head->val == ans.back())
                    count++;
                else
                    count = 1;
                ans += head->val;
                head = head->next;
            }else{
                ListNode *tmp = head;
                while(tmp && (tmp->val == head->val || tmp->val == '#'))
                    tmp = tmp->next;
                if(tmp){
                    ans += tmp->val;
                    tmp->val = '#';
                    count = 0;
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_2182_H
