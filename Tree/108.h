//
// Created by QinJM on 2023/9/24.
//

#ifndef LEETCODE_108_H
#define LEETCODE_108_H
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return func(nums, 0, nums.size()-1);
    }
    TreeNode* func(vector<int> &nums, int begin, int end){
        if(begin > end)
            return nullptr;

        int middle = (begin + end) / 2;
        TreeNode *node = new TreeNode(nums[middle]);
        node->left = func(nums, begin, middle-1);
        node->right = func(nums, middle+1, end);
        return node;
    }
};

#endif //LEETCODE_108_H
