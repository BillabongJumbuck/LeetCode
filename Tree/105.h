    //
// Created by QinJM on 2023/10/15.
//

#ifndef LEETCODE_105_H
#define LEETCODE_105_H
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
private:
    int findX(vector<int> v, int x){
        for(int i : v){
            if(v[i] == x)
                return i;
        }
        return -1;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())
            return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);
        int x = findX(inorder, preorder[0]);
        vector<int> leftpreorder, leftinorder;
        for(int i=0;i<x;++i) {
            leftpreorder.push_back(preorder[i + 1]);
            leftinorder.push_back(inorder[i]);
        }
        root->left = buildTree(leftpreorder, leftinorder);
        vector<int> rightpreorder, rightinorder;
        for(int i=x+1;i<preorder.size();++i) {
            rightpreorder.push_back(preorder[i]);
            rightinorder.push_back(inorder[i]);
        }
        root->right = buildTree(rightpreorder, rightinorder);
        return root;
    }
    // 迭代解法
    TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder){
        if(preorder.empty())
            return nullptr;
        TreeNode *root = new TreeNode(preorder[0]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = 0;
        for (int i=1;i<preorder.size();++i ){
            int preorderVal = preorder[i];
            TreeNode* node = stk.top();
            if(node->val != inorder[inorderIndex]){
                node->left = new TreeNode(preorderVal);
                stk.push(node->left);
            }
            else{
                while(!stk.empty() && stk.top()->val == inorder[inorderIndex]){
                    node = stk.top();
                    stk.pop();
                    ++inorderIndex;
                }
                node->right = new TreeNode(preorderVal);
                stk.push(node->right);
            }
        }
        return root;
    }
};


#endif //LEETCODE_105_H
