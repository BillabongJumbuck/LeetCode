//
// Created by QinJM on 2023/12/11.
//

#ifndef LEETCODE_590_H
#define LEETCODE_590_H
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
public:
    void dfs(Node *node, vector<int> &v){
        if(node){
            for(auto i : node->children){
                dfs(i, v);
            }
            v.push_back(node->val);
        }
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> ret;
        if(root == nullptr)
            return ret;
        dfs(root, ret);
        return ret;
    }
};

#endif //LEETCODE_590_H
