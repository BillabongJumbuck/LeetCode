//
// Created by QinJM on 2023/9/17.
//

#ifndef LEETCODE_100_H
#define LEETCODE_100_H
#include <stack>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s1, s2;
        if( p== nullptr && q== nullptr){
            return true;
        }
        else if(p == nullptr || q== nullptr)
            return false;
        else{
            while((p||!s1.empty()) && (q||!s2.empty())){
                while(p||q){
                    s1.push(p);
                    s2.push(q);
                    if(p->val != q->val){
                        return false;
                    }
                    p=p->left;
                    q=q->left;
                    if((p == nullptr && q!= nullptr) || ( q== nullptr && p!= nullptr))
                        return false;
                }
                p = s1.top();
                q = s2.top();
                p = p->right;
                q = q->right;
                if((p == nullptr && q!= nullptr) || ( q== nullptr && p!= nullptr))
                    return false;
                s1.pop();
                s2.pop();
            }
            return true;
        }
    }
};
#endif //LEETCODE_100_H
