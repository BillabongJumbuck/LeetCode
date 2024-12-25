//
// Created by QinJM on 2023/10/12.
//

#ifndef LEETCODE_114_H
#define LEETCODE_114_H
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
    void flatten(TreeNode* root) {
        TreeNode *leftNode, *rightNode;
        while(root){
            if(root->left){
                rightNode = root->right;
                leftNode = root->left;
                while(leftNode->right)
                    leftNode = leftNode->right;
                root->right = root->left;
                root->left = nullptr;
                leftNode->right = rightNode;
            }
            root = root->right;
        }
    }
};
#endif //LEETCODE_114_H
