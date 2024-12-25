//
// Created by QinJM on 2023/11/30.
//

#ifndef LEETCODE_138_H
#define LEETCODE_138_H
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr)
            return nullptr;
        Node *new_head = new Node(head->val);
        Node *count = new_head;
        Node *tmp = head->next;
        while(tmp){
            Node *node = new Node(tmp->val);
            count->next = node;
            tmp = tmp->next;
        }
        tmp = head;
        count = new_head;
        while(tmp){
            if(tmp->random){
                Node *a = head;
                int x = 0;
                while(a != tmp->random){
                    x++;
                    a = a->next;
                }
                Node *b = new_head;
                while(x>0){
                    x--;
                    b = b->next;
                }
                count->random = b;
            }
            tmp = tmp->next;
            count = count->next;
        }
        return new_head;
    }
};
#endif //LEETCODE_138_H
