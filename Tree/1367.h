//
// Created by QinJM on 24-12-30.
//

#ifndef LEETCODE_1367_H
#define LEETCODE_1367_H
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool dfs(ListNode *head, TreeNode* root){
        if(head == nullptr)
            return true;
        if(root == nullptr)
            return false;
        if(head->val != root->val)
            return false;
        return dfs(head->next, root->left) || dfs(head->next, root->right);
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == nullptr){
            return false;
        }
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
#endif //LEETCODE_1367_H
