//
// Created by QinJM on 2023/9/23.
//

#ifndef LEETCODE_404_H
#define LEETCODE_404_H

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            root = q.front(); q.pop();
            if(root->left != nullptr) {
                q.push(root->left);
                if (root->left->left == nullptr && root->left->right == nullptr)
                    sum += root->left->val;
            }
            if(root->right != nullptr){
                q.push(root->right);
            }
        }
        return sum;
    }
};
#endif //LEETCODE_404_H
