//
// Created by QinJM on 2024/1/2.
//

#ifndef LEETCODE_450_H
#define LEETCODE_450_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
private:
    TreeNode* find_min(TreeNode* root){
        if(root == nullptr)
            return root;
        else if(root->right == nullptr)
            return root;
        else
            return find_min(root->left);
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        TreeNode *tmp = nullptr;
        if(key < root->val)
            root->left = deleteNode(root->left, key);
        else if(key > root->val)
            root->right = deleteNode(root->right, key);
        else{
            if(root->left && root->right){
                tmp = find_min(root->right);
                root->val = tmp->val;
                root->right = deleteNode(root->right, root->val);
            }else{
                tmp = root;
                if(root->left == nullptr)
                    root = root->right;
                else
                    root = root->left;
                delete tmp;
            }
        }
        return root;
    }
};
#endif //LEETCODE_450_H
