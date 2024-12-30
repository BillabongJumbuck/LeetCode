//
// Created by QinJM on 2023/9/26.
//

#ifndef LEETCODE_543_H
#define LEETCODE_543_H

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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root){
            int HL, HR;
            HL = getHeight(root->left);
            HR = getHeight(root->right);
            return Max(HL+HR, diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        }
        return 0;
    }
private:
    int getHeight(TreeNode* T){
        if(T){
            int HL, HR ,HM;
            HL = getHeight(T->left);
            HR = getHeight(T->right);
            HM = HL>HR?HL:HR;
            return (1+HM);
        }
        return 0;
    }
    int Max(int a,int b,int c){
        return std::max(a, std::max(b, c));
    }
};
#endif //LEETCODE_543_H
