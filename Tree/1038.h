//
// Created by QinJM on 2023/12/4.
//

#ifndef LEETCODE_1038_H
#define LEETCODE_1038_H
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
    int sum = 0;
public:
    // 二叉树的反向中序遍历
    TreeNode* bstToGst(TreeNode* root) {
        if(root){
            bstToGst(root->right);
            sum += root->val;
            root->val = sum;
            bstToGst(root->left);
        }
        return root;
    }
};
#endif //LEETCODE_1038_H
