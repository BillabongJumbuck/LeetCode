//
// Created by QinJM on 2023/9/24.
//

#ifndef LEETCODE_199_H
#define LEETCODE_199_H
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(root == nullptr)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            size_t size = q.size();
            while(size>0){
                root = q.front(); q.pop();
                if(size == 1)
                    v.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                --size;
            }
        }
        return v;
    }
};
#endif //LEETCODE_199_H
