//
// Created by QinJM on 2023/9/22.
//

#ifndef LEETCODE_226_H
#define LEETCODE_226_H
#include <queue>
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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        queue<TreeNode*> q;
        TreeNode *t  = nullptr, *temp = nullptr;
        q.push(root);
        while(!q.empty()){
            t=q.front();q.pop();
            if(t->left== nullptr && t->right== nullptr)
                continue;
            else{
                if(t->left != nullptr) q.push(t->left);
                if(t->right != nullptr) q.push(t->right);
            }
            temp=t->left;
            t->left=t->right;
            t->right=temp;
        }
        return root;
    }
};
#endif //LEETCODE_226_H
