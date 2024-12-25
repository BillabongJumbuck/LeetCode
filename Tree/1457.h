//
// Created by QinJM on 2023/11/25.
//

#ifndef LEETCODE_1457_H
#define LEETCODE_1457_H
#include <vector>
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
private:
    bool isValid(vector<int> nums){
        vector<int> *flag = new vector(10,0);
        int odd = 0;
        for(int i:nums){
            (flag->at(i))++;
            if((flag->at(i)) % 2)
                odd++;
            else
                odd--;
        }
        return odd==1;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root == nullptr)
            return 0;
        queue<TreeNode*> *qtree = new queue<TreeNode*>();
        qtree->push(root);
        queue<vector<int>> *qpath = new queue<vector<int>>();
        qpath->push(vector<int>{root->val});
        int ret = 0 ;
        while(!qtree->empty()){
            int size = qtree->size();
            while(size>0){
                root = qtree->front(); qtree->pop();
                if(!root->left && !root->right){
                    vector<int> tmp = qpath->front();
                    if(isValid(tmp))
                        ret++;
                }
                if(root->left){
                    qtree->push(root->left);
                    vector<int> tmp = qpath->front();
                    tmp.push_back(root->left->val);
                    qpath->push(tmp);
                }
                if(root->right){
                    qtree->push(root->right);
                    vector<int> tmp = qpath->front();
                    tmp.push_back(root->right->val);
                    qpath->push(tmp);
                }
                qpath->pop();
                size--;
            }
        }
        return ret;
    }
};
#endif //LEETCODE_1457_H
