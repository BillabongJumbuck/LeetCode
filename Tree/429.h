//
// Created by QinJM on 2023/11/27.
//

#ifndef LEETCODE_429_H
#define LEETCODE_429_H
#include <vector>
#include <queue>
using namespace std;
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ret;
        if(root == nullptr)
            return ret;
        queue<Node*> open;
        open.push(root);
        while(!open.empty()){
            int size = open.size();
            vector<int> layer;
            while(size>0){
                root = open.front();
                open.pop();
                layer.push_back(root->val);
                if(!root->children.empty()){
                    for(auto i : root->children){
                        open.push(i);
                    }
                }
                size--;
            }
            ret.push_back(layer);
        }
        return ret;
    }
};
#endif //LEETCODE_429_H
