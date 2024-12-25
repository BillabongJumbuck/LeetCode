//
// Created by QinJM on 2024/1/15.
//

#ifndef LEETCODE_530_H
#define LEETCODE_530_H
#include <stack>
#include <cmath>
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
    int getMinimumDifference(TreeNode* root) {
        int min = INT_MAX;
        int prev = -1;
        stack<TreeNode*> stk;
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top(); stk.pop();
            if(prev == -1){
                prev = root->val;
            }else{
                int tmp = abs(prev - root->val);
                if(tmp < min){
                    min = tmp;
                }
                prev = root->val;
            }
            root = root->right;
        }
        return min;
    }
};
#endif //LEETCODE_530_H
