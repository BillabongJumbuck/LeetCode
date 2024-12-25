//
// Created by QinJM on 2023/9/21.
//

#ifndef LEETCODE_257_H
#define LEETCODE_257_H
#include<vector>
#include<string>
#include<queue>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        if(root == nullptr)
            return v;
        queue<TreeNode*> q1;
        queue<string> q2;
        string s;
        q1.push(root);
        q2.push(to_string(root->val));
        while(!q1.empty()){
            root=q1.front(); q1.pop();
            s=q2.front();q2.pop();
            if(root->left != nullptr){
                q1.push(root->left);
                q2.push(s+"->"+to_string(root->left->val));
            }
            if(root->right != nullptr){
                q1.push(root->right);
                q2.push(s+"->"+to_string(root->right->val));
            }
            if(root->left == nullptr&&root->right == nullptr){
                v.push_back(s);
            }
        }
        return v;
    }
};
#endif //LEETCODE_257_H
