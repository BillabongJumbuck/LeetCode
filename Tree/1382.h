//
// Created by QinJM on 2023/10/31.
//

#ifndef LEETCODE_1382_H
#define LEETCODE_1382_H
#include <stack>
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
private:
    int getHeight(TreeNode *root){
        if(root){
            int HL, HR, HMX;
            HL = getHeight(root->left);
            HR = getHeight(root->right);
            HMX = HL>HR ? HL : HR;
            return 1+HMX;
        }
        return 0;
    }
    TreeNode* SingLeftRotation(TreeNode* A){
        TreeNode* B = A;
        A->left = B->right;
        B->right = A;
        return B;
    }
    TreeNode* SingRightRotation(TreeNode* A){
        TreeNode* B = A;
        A->right = B->left;
        B->left = A;
        return B;
    }
    TreeNode* DoubleLeftRightRotation(TreeNode* A){
        A->left = SingRightRotation(A->left);
        return SingLeftRotation(A);
    }
    TreeNode* DoubleRightLeftRotation(TreeNode* A){
        A->right = SingRightRotation(A->right);
        return SingRightRotation(A);
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        TreeNode* head = root;
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size>0){
                root = q.front(); q.pop();
                s.push(root);
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
                --size;
            }
        }
        while (!s.empty()){
            root = s.top(); s.pop();
            if(getHeight(root->left) - getHeight(root->right) == 2){
                if(root->left->left)
                    root = SingLeftRotation(root);
                if(root->left->right)
                    root = DoubleLeftRightRotation(root);
            }
            if(getHeight(root->right) - getHeight(root->left) == 2){
                if(root->right->right)
                    root = SingRightRotation(root);
                if(root->right->left)
                    root = DoubleRightLeftRotation(root);
            }
        }
        return head;
    }
};
#endif //LEETCODE_1382_H
