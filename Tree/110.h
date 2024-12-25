//
// Created by QinJM on 2023/9/20.
//

#ifndef LEETCODE_110_H
#define LEETCODE_110_H
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
            int HL, HR, HM;
            HL = getHeight(root->left);
            HR = getHeight(root->right);
            HM = HL > HR ? HL : HR;
            return  1 + HM;
        }
        return 0;
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root){
            int height = getHeight(root->left) - getHeight(root->right);
            bool flag = height==0 || height==1 || height==-1;
            return flag && isBalanced(root->left) && isBalanced(root->right);
        }
        return true;
    }
};


//class Solution {
//public:
//    bool isBalanced(TreeNode* root) {
//        if(root == nullptr)
//            return false;
//        queue<TreeNode*> q;
//        q.push(root);
//        while(!q.empty()){
//            root=q.front();
//            q.pop();
//            if(!func(root))
//                return false;
//            if(root->left) q.push(root->left);
//            if(root->right) q.push(root->right);
//        }
//        return true;
//    }
//    bool func(TreeNode* root){
//        int HD;
//        HD= getHeight(root->left)-getHeight(root->right);
//        if(HD==1 || HD==0 || HD==-1) return true;
//        else return false;
//    }
//    int getHeight(TreeNode* root){
//        int HL ,HR ,HM;
//        if(root){
//            HL= getHeight(root->left);
//            HR= getHeight(root->right);
//            HM= HL>HR?HL:HR;
//            return (1+HM);
//        }
//        return 0;
//    }
//
//};
#endif //LEETCODE_110_H
