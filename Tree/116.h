//
// Created by QinJM on 2023/10/11.
//

#ifndef LEETCODE_116_H
#define LEETCODE_116_H
#include<queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
            return nullptr;
        queue<Node*> q;
        Node *head = root;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                root = q.front(); q.pop();
                --size;
                if(size == 0)
                    root->next = nullptr;
                else
                    root->next = q.front();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
        }
        return head;
    }
};
#endif //LEETCODE_116_H
