//
// Created by QinJM on 2023/12/15.
//

#ifndef LEETCODE_2415_H
#define LEETCODE_2415_H
#include <deque>
using std::deque;
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
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        deque<TreeNode*> q;
        q.push_back(root);
        int count = 0;
        while (!q.empty()){
            int size = q.size();
            if(count%2==1){
                int i=0;
                int j=size-1;
                while(i<j){
                    int tmp = q[i]->val;
                    q[i]->val = q[j]->val;
                    q[j]->val = tmp;
                    i++;
                    j--;
                }
            }
            while(size>0){
                TreeNode* tmp = q.front(); q.pop_front();
                if(tmp->left)
                    q.push_back(tmp->left);
                if(tmp->right)
                    q.push_back(tmp->right);
                size--;
            }
            count++;
        }
        return root;
    }
};
#endif //LEETCODE_2415_H
