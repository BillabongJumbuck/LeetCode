//
// Created by QinJM on 2024/1/3.
//

#ifndef LEETCODE_2487_H
#define LEETCODE_2487_H
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
private:
    ListNode* find_max(ListNode *head){
        if(head== nullptr)
            return nullptr;
        else{
            ListNode *max_node = head;
            int max_val = head->val;
            while(head){
                if(head->val > max_val){
                    max_node = head;
                    max_val = head->val;
                }
                head = head->next;
            }
            return max_node;
        }
    }
    bool is_step(ListNode *head){
        if(head == nullptr)
            return true;
        while(head->next){
            if(head->val < head->next->val)
                return false;
            head = head->next;
        }
        return true;
    }
public:
    ListNode* removeNodes(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        ListNode *dummy = new ListNode();
        ListNode *node = dummy;
        ListNode *max_node = find_max(head);
        while(max_node){
            ListNode *tmp = head;
            head = max_node->next;
            node->next = max_node;
            node = node->next;
            node->next = nullptr;
            while(tmp != max_node){
                ListNode *del = tmp;
                tmp = tmp->next;
                delete del;
            }
            if(is_step(head)){
                node->next = head;
                break;
            }
            max_node = find_max(head);
        }
        ListNode *del = dummy;
        dummy = dummy->next;
        delete del;
        return dummy;
    }
};
#endif //LEETCODE_2487_H
