//
// Created by QinJM on 2023/9/18.
//

#ifndef LEETCODE_101_H
#define LEETCODE_101_H
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
public:
//    两个队列
//    bool isSymmetric(TreeNode* root) {
//        TreeNode *tl = nullptr, *tr = nullptr;
//        if (root == nullptr)
//            return true;
//        tl = root->left;
//        tr = root->right;
//        queue<TreeNode *> ql, qr;
//        if (tl == nullptr && tr == nullptr) {
//            return true;
//        } else if (((tl == nullptr) ^ (tr == nullptr)) == 1) {
//            return false;
//        } else {
//            for (;;) {
//                if (tl && tr) {
//                    if (tl->val != tr->val) {
//                        return false;
//                    }
//                    if (tl->left && tr->right) {
//                        ql.push(tl->left);
//                        qr.push(tr->right);
//                    } else if (tl->left == nullptr && tr->right == nullptr) {
//                    } else {
//                        return false;
//                    }
//                    if (tr->left && tl->right) {
//                        ql.push(tl->right);
//                        qr.push(tr->left);
//                    } else if (tr->left == nullptr && tl->right == nullptr) {
//                    } else {
//                        return false;
//                    }
//                    if (ql.empty() && qr.empty())
//                        return true;
//                    tl = ql.front();
//                    tr = qr.front();
//                    ql.pop();
//                    qr.pop();
//                }
//            }
//        }
//    }
//  一个队列
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        TreeNode *tl, *tr;
        queue<TreeNode*> q;
        tl=root->left;
        tr=root->right;
        if(tl == nullptr && tr == nullptr)
            return true;
        else if(((tl== nullptr)^(tr== nullptr))==1){
            return false;
        }
        for(;;){
            if(tl->val != tr->val)
                return false;
            if (tl->left && tr->right) {
                q.push(tl->left);
                q.push(tr->right);
            } else if (tl->left == nullptr && tr->right == nullptr) {
            } else {
                return false;
            }
            if (tr->left && tl->right) {
                q.push(tl->right);
                q.push(tr->left);
            } else if (tr->left == nullptr && tl->right == nullptr) {
            } else {
                return false;
            }
            if(q.empty())
                return true;
            tl = q.front();
            tr = q.front();
            q.pop();
            q.pop();
        };
    }
};
#endif //LEETCODE_101_H
