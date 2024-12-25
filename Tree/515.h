//
// Created by QinJM on 2024/1/17.
//

#ifndef LEETCODE_515_H
#define LEETCODE_515_H
#include <vector>
#include <queue>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int min = INT_MIN;
            while(size-- > 0){
                root = q.front();
                q.pop();
                if(root->val > min)
                    min = root->val;
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
            }
            ans.push_back(min);
        }
        return ans;
    }
};
#endif //LEETCODE_515_H
