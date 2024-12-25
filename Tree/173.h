//
// Created by QinJM on 2023/10/31.
//

#ifndef LEETCODE_173_H
#define LEETCODE_173_H
#include <stack>
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
class BSTIterator {
    vector<int> output;
    int i = 0;
public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> s;
        while(root && !s.empty()){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top(); s.pop();
            output.push_back(root->val);
            root = root->right;
        }
    }
    int next() {
        return output[i++];
    }

    bool hasNext() {
        if(i<output.size()-2)
            return true;
        return false;
    }
};
#endif //LEETCODE_173_H
