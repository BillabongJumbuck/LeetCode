//
// Created by QinJM on 2023/9/23.
//

#ifndef LEETCODE_102_H
#define LEETCODE_102_H
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root == nullptr)
            return v;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> tmp;
            while(size>0){
                root = q.front(); q.pop();
                tmp.push_back(root->val);
                if(root->left){
                    q.push(root->left);
                }
                if(root->right){
                    q.push(root->right);
                }
                --size;
            }
            v.push_back(tmp);
        }
        return v;
    }
};
#endif //LEETCODE_102_H
