//
// Created by QinJM on 2024/1/4.
//

#ifndef LEETCODE_99_H
#define LEETCODE_99_H
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
private:
    TreeNode* find_min(TreeNode *root){
        TreeNode *min = root;
        int min_val = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            root = q.front(); q.pop();
            if(root->val < min_val) {
                min_val = root->val;
                min = root;
            }
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        return min;
    }
    TreeNode* find_max(TreeNode *root){
        TreeNode *max = root;
        int max_val = root->val;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            root = q.front(); q.pop();
            if(root->val > max_val){
                max_val = root->val;
                max = root;
            }
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
        }
        return max;
    }
    void swap(TreeNode *a, TreeNode *b){
        int tmp = a->val;
        a->val = b->val;
        b->val = tmp;
    }
public:
    void recoverTree(TreeNode* root) {
        if(root == nullptr)
            return;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *min;
        TreeNode *max;
        while(!q.empty()){
            root = q.front(); q.pop();
            if(root->left && root->right){
                max = find_max(root->left);
                min = find_min(root->right);
                if (max->val>root->val && min->val<root->val){
                    swap(max, min);
                    return;
                }
                if (max->val > root->val) {
                    swap(max, root);
                    return;
                }
                if (min->val < root->val){
                    swap(min, root);
                    return;
                }
                q.push(root->left);
                q.push(root->right);
            }
            else if(root->left) {
                max = find_max(root->left);
                if (max->val > root->val) {
                    swap(max, root);
                    return;
                }
                q.push(root->left);
            }
            else if(root->right){
                min = find_min(root->right);
                if (min->val < root->val){
                    swap(min, root);
                    return;
                }
                q.push(root->right);
            }
        }
    }
};
#endif //LEETCODE_99_H
