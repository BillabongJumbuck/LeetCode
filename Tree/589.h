//
// Created by QinJM on 2023/12/9.
//

#ifndef LEETCODE_589_H
#define LEETCODE_589_H
#include <vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    void dfs(Node *node, vector<int> &v){
        if(node){
            v.push_back(node->val);
            for(auto i : node->children){
                dfs(i , v);
            }
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ret;
        if(root == nullptr)
            return ret;
        dfs(root, ret);
        return ret;
    }
};
#endif //LEETCODE_589_H
