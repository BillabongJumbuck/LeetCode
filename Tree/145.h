//
// Created by QinJM on 2023/9/17.
//

#ifndef LEETCODE_145_H
#define LEETCODE_145_H
#include <vector>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s1,s2;
        vector<int> v;
        while(root || !s1.empty() || !s2.empty()){
            while(root){
                s1.push(root);
                root=root->left;
            }
            root=s1.top();
            s2.push(root);
            root = root->right;
            s1.pop();
        }
        return v;
    }
};

#endif //LEETCODE_145_H
