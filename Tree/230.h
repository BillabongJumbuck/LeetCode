//
// Created by QinJM on 2023/12/28.
//

#ifndef LEETCODE_230_H
#define LEETCODE_230_H
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
    void inorder_traversal(TreeNode *root, vector<int>& v){
        if(root){
            inorder_traversal(root->left, v);
            v.push_back(root->val);
            inorder_traversal(root->right,v);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> traversal;
        inorder_traversal(root, traversal);
        return traversal[k-1];
    }
};
#endif //LEETCODE_230_H
