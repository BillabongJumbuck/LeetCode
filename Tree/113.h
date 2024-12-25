//
// Created by QinJM on 2023/10/25.
//

#ifndef LEETCODE_113_H
#define LEETCODE_113_H
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if( root == nullptr)
            return ans;
        queue<TreeNode*> tree;
        queue<int> sum;
        queue<vector<int>> path;
        vector<int> p = {root->val};
        tree.push(root);
        sum.push(root->val);
        path.push(p);
        while(!tree.empty()){
            int size = tree.size();
            while(size>0){
                root = tree.front();
                int val = sum.front();
                vector<int> tmp = path.front();
                if(root->left == nullptr && root->right == nullptr){
                    if(val == targetSum)
                        ans.push_back(tmp);
                }
                else {
                    if (root->left) {
                        tree.push(root->left);
                        sum.push(val + root->left->val);
                        tmp = path.front();
                        tmp.push_back(root->left->val);
                        path.push(tmp);
                    }
                    if (root->right) {
                        tree.push(root->right);
                        sum.push(val + root->right->val);
                        tmp = path.front();
                        tmp.push_back(root->right->val);
                        path.push(tmp);
                    }
                }
                tree.pop();
                sum.pop();
                path.pop();
                --size;
            }
        }
        return ans;
    }
};
//深度优先搜索
class Solution2 {
private:
    vector<vector<int>> ret;
    vector<int> path;
    void dfs(TreeNode* root, int targetSum){
        if( root == nullptr)
            return;
        path.push_back(root->val);
        targetSum -= root->val;
        if(root->left == nullptr && root->right == nullptr && targetSum == 0)
            ret.push_back(path);
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ret;
    }
};
#endif //LEETCODE_113_H
