//
// Created by QinJM on 2023/10/22.
//

#ifndef LEETCODE_129_H
#define LEETCODE_129_H
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
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<TreeNode*> tree;
        queue<int> num;
        tree.push(root);
        num.push(root->val);
        int sum = 0;
        while(!tree.empty()){
            int size  = tree.size();
            while(size>0){
                root = tree.front(); tree.pop();
                int val = num.front(); num.pop();
                if(root ->left == nullptr && root->right == nullptr)
                    sum+=val;
                else{
                    if(root->left){
                        tree.push(root->left);
                        num.push(val*10 + root->left->val);
                    }
                    if(root->right){
                        tree.push(root->right);
                        num.push(val*10 + root->right->val);
                    }
                }
                --size;
            }
        }
        return sum;
    }
};
#endif //LEETCODE_129_H
