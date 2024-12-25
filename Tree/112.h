//
// Created by QinJM on 2023/9/21.
//

#ifndef LEETCODE_112_H
#define LEETCODE_112_H
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)
            return false;
        queue<TreeNode*> q1;
        queue<int> q2;
        q1.push(root);
        q2.push(root->val);
        while(!q1.empty()){
            root = q1.front();q1.pop();
            int i=q2.front();q2.pop();
            if(root->left== nullptr && root->right== nullptr){
                if(i==targetSum)
                    return true;
            }else{
                if(root->left != nullptr){
                    q1.push(root->left);
                    q2.push(i+root->left->val);
                }
                if(root->right != nullptr){
                    q1.push(root->right);
                    q2.push(i+root->right->val);
                }
            }
        }
        return false;
    }
};
#endif //LEETCODE_112_H
