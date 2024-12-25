//
// Created by QinJM on 2023/10/16.
//

#ifndef LEETCODE_559_H
#define LEETCODE_559_H
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
    int maxDepth(Node* root) {
        if( root == nullptr)
            return 0;
        int depth = 0;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                root = q.front(); q.pop();
                if(!root->children.empty()){
                    for(auto i : root->children){
                        q.push(i);
                    }
                }
                --size;
            }
            ++depth;
        }
        return depth;
    }
};
#endif //LEETCODE_559_H
