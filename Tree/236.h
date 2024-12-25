//
// Created by QinJM on 2023/11/23.
//

#ifndef LEETCODE_236_H
#define LEETCODE_236_H
#include <deque>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> layer;
        deque<deque<TreeNode*>> paths;
        deque<TreeNode*> path_p;
        deque<TreeNode*> path_q;
        layer.push_back(root);
        paths.push_back(deque<TreeNode*>{root});
        while(!layer.empty()){
            int size = layer.size();
            while(size>0){
                root = layer.front(); layer.pop_front();
                if(root == p)
                    path_p = paths.front();
                if(root == q)
                    path_q = paths.front();
                if(!path_p.empty() && !path_q.empty()){
                    size = 0;
                    layer.clear();
                }else{
                    --size;
                }
                if(root->left || root->right){
                    if(root->left){
                        deque<TreeNode*> tmp = paths.front();
                        tmp.push_back(root->left);
                        paths.push_back(tmp);
                        layer.push_back(root->left);
                    }
                    if(root->right){
                        deque<TreeNode*> tmp = paths.front();
                        tmp.push_back(root->right);
                        paths.push_back(tmp);
                        layer.push_back(root->right);
                    }

                }
                paths.pop_front();
            }
        }
        int i=0;
        for(;i<(path_q.size()>path_p.size()?path_p.size():path_q.size());++i){
            if(path_q[i] != path_p[i])
                break;
        }
        return path_p[i-1];
    }
};
#endif //LEETCODE_236_H
