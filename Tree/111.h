//
// Created by QinJM on 2023/9/20.
//

#ifndef LEETCODE_111_H
#define LEETCODE_111_H
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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<TreeNode*> q;
        int ans=0, s;
        q.push(root);
        while(!q.empty()){
            s=q.size();
            while(s>0){
                root=q.front(); q.pop();
                if(root->left == nullptr && root->right == nullptr)
                    return 1+ans;
                if(root->left != nullptr) q.push(root->left);
                if(root->right !=nullptr) q.push(root->right);
                --s;
            }
            ans+=1;
        }
        return -1;
    }
};
#endif //LEETCODE_111_H
