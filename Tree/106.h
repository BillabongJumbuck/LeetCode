//
// Created by QinJM on 2023/10/17.
//

#ifndef LEETCODE_106_H
#define LEETCODE_106_H
#include <stack>
#include <vector>
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())
            return nullptr;

        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = inorder.size()-1;
        for(int i = postorder.size()-2;i>=0;--i){
            TreeNode* node = stk.top();
            int postorderVal = postorder[i];
            if(node->val != inorder[inorderIndex]){
                node->right = new TreeNode(postorderVal);
                stk.push(node->right);
            }
            else{
                while(!stk.empty() && stk.top()->val == inorder[inorderIndex]){
                    node = stk.top();
                    stk.pop();
                    --inorderIndex;
                }
                node->left = new TreeNode(postorderVal);
                stk.push(node->left);
            }
        }
        return root;
    }
};
#endif //LEETCODE_106_H
