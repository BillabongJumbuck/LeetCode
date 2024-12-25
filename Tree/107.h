//
// Created by QinJM on 2023/10/4.
//

#ifndef LEETCODE_107_H
#define LEETCODE_107_H
#include<vector>
#include<stack>
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
class Solution{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root){
        vector<vector<int>> v;
        if(root == nullptr)
            return v;
        queue<TreeNode*> q;
        queue<TreeNode*> qt;
        stack<queue<TreeNode*>> s;
        q.push(root);
        qt.push(root);
        s.push(q);
        while(!q.empty()){
            queue<TreeNode*> qtt;
            int size = q.size();
            while(size>0){
                root = q.front(); q.pop();
                qtt.push(root);
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                --size;
            }
            s.push(qtt);
        }
        while(!s.empty()){
            qt = s.top();s.pop();
            vector<int> tmp;
            while(!qt.empty()){
                root = qt.front();qt.pop();
                tmp.push_back(root->val);
            }
            v.push_back(tmp);
        }
        return v;
    }
};
#endif //LEETCODE_107_H
