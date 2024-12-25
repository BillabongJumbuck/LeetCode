//
// Created by QinJM on 2023/9/25.
//

#ifndef LEETCODE_98_H
#define LEETCODE_98_H
#include<stack>
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
    bool isValidBST(TreeNode* root) {
        if (!root || (!root->left && !root->right))
            return true;
        TreeNode *tmp = root;
        int num = root->val;
        stack<TreeNode *> s;
        tmp = root->left;
        while( tmp || !s.empty()){
            while(tmp){
                s.push(tmp);
                if(tmp->val >= num)
                    return false;
                tmp=tmp->left;
            }
            tmp = s.top();
            tmp = tmp->right;
            s.pop();
        }
        tmp = root->right;
        while( tmp || !s.empty()){
            while(tmp){
                s.push(tmp);
                if(tmp->val <= num)
                    return false;
                tmp=tmp->left;
            }
            tmp = s.top();
            tmp = tmp->right;
            s.pop();
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
#endif //LEETCODE_98_H
