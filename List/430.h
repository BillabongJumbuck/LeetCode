//
// Created by QinJM on 2023/11/21.
//

#ifndef LEETCODE_430_H
#define LEETCODE_430_H

#include <stack>
using std::stack;
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr)
            return nullptr;
        Node* node = head;
        stack<Node*> s;
        while(true){
            while(true){
                if(node->child){
                    if(node->next)
                        s.push(node->next);
                    node->next = node->child;
                    node->child->prev = node;
                    node->child = nullptr;
                }
                if(node->next == nullptr)
                    break;
                else
                    node = node->next;
            }
            if(s.empty())
                break;
            else{
                node->next = s.top();
                node->next->prev = node;
                s.pop();
            }
        }
        return head;
    }
};
#endif //LEETCODE_430_H
