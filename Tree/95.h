//
// Created by QinJM on 2023/10/19.
//

#ifndef LEETCODE_95_H
#define LEETCODE_95_H
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
    vector<TreeNode*> ans;
private:
    TreeNode* buildTree(TreeNode *head,vector<int>& nums, int begin, int end, int count){
        if(begin > end)
            return nullptr;
        for(int i=begin;i<end;++i){
            TreeNode *node = new TreeNode(nums[i]);
            --count;
            node->left = buildTree(head,nums, begin, i-1, count);
            node->right = buildTree(head, nums, i+1, end, count);
            if(count == 0)
                ans.push_back(head);
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if( n ==0 )
            return ans;
        vector<int> v;
        for(int i=1;i<=n;++i)
            v.push_back(i);
        int begin = 0;
        int end = v.size();
        for(int i=begin;i<end;++i){
            TreeNode *head = new TreeNode(v[i]);
            ++n;
            head->left = buildTree(head,v, begin, i-1, n);
            head->right = buildTree(head, v, i+1, end, n);
        }
        return ans;
    }
};
#endif //LEETCODE_95_H
