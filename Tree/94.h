//
// Created by QinJM on 2023/9/16.
//

#ifndef LEETCODE_94_H
#define LEETCODE_94_H

#include<vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *predecessor = nullptr;

        while(root){
            if (root->left){
                predecessor = root->left;
                while(predecessor->right && predecessor != root){
                    predecessor = predecessor->right;
                }
                if(predecessor->right == nullptr){
                    predecessor->right=root;
                    root=root->left;
                }
                else{
                    res.push_back(root->val);
                    predecessor->right = nullptr;
                    root = root -> right;
                }
            }
            else{
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;

    }
};

//递归
//public:
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> vl,vr;
//        if(root){
//            vl=inorderTraversal(root->left);
//            vl.insert(vl.end(),root->val);
//            vr= inorderTraversal(root->right);
//            vl.insert(vl.end(),vr.begin(),vr.end());
//        }
//        return vl;
//    }
//};

//非递归版本
//public:
//vector<int> inorderTraversal(TreeNode* root) {
//    vector<TreeNode*> t;
//    vector<int> v;
//    while(root || t.size() != 0){
//        while(root) {
//            t.push_back(root);
//            root = root->left;
//        }
//        root = t.back();
//        v.push_back(root->val);
//        root=root->right;
//        t.pop_back();
//    }
//    return v;
//}
#endif //LEETCODE_94_H
