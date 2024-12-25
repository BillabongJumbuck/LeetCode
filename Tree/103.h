//
// Created by QinJM on 2023/10/6.
//

#ifndef LEETCODE_103_H
#define LEETCODE_103_H
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
private:
    void reverse(vector<int>& vec){
        int tmp;
        for(int i = 0;i<vec.size()/2;++i){
            tmp = vec[i];
            vec[i] = vec[vec.size()-i];
            vec[vec.size()-1-i] = tmp;
        }
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if( root == nullptr )
            return v;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 1;
        while(!q.empty()){
            int size = q.size();
            vector<int> tmp;
            while(size>0){
                root = q.front(); q.pop();
                tmp.push_back(root->val);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                --size;
            }
            if(flag % 2 == 0)
                reverse(tmp);
            v.push_back(tmp);
            ++flag;
        }
        return v;
    }
};
#endif //LEETCODE_103_H
