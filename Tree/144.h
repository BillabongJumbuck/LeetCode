//
// Created by QinJM on 2023/9/17.
//

#ifndef LEETCODE_144_H
#define LEETCODE_144_H
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        func(root,v);
        return v;
    }
    void func(TreeNode* root, vector<int>& v){
        if(root){
            v.push_back(root->val);
            func(root->left,v);
            func(root->right,v);
        }
    }
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> v;
//        stack<TreeNode*> s;
//        while(root || !s.empty()){
//            while(root){
//                v.push_back(root->val);
//                s.push(root);
//                root = root->left;
//            }
//            root = s.top();
//            root = root->right;
//            s.pop();
//        }
//        return v;
//    }
};
#endif //LEETCODE_144_H
