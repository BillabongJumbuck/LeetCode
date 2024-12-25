//
// Created by QinJM on 2023/12/26.
//

#ifndef LEETCODE_654_H
#define LEETCODE_654_H
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
    int find_max(vector<int>& v, int begin, int end){
        int max_num = -1;
        int max_index = -1;
        while(begin<=end){
            if(v[begin]>max_num){
                max_num = v[begin];
                max_index = begin;
            }
            begin++;
        }
        return max_index;
    }
    TreeNode* build_tree(vector<int>& v, int begin, int end){
        TreeNode *node = nullptr;
        if(begin<=end){
            int max_index = find_max(v, begin, end);
            node = new TreeNode(v[max_index]);
            node->left = build_tree(v, begin, max_index-1);
            node->right = build_tree(v, max_index+1, end);
        }
        return node;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build_tree(nums, 0, nums.size()-1);
    }
};
#endif //LEETCODE_654_H
