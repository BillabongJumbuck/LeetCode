//
// Created by QinJM on 2023/12/21.
//

#ifndef LEETCODE_109_H
#define LEETCODE_109_H

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
    TreeNode *func(ListNode *head, int begin, int end){
        if(begin<=end){
            int middle = (begin+end)/2;
            ListNode *tmp = head;
            int count = middle -1;
            while(count > 0){
                count--;
                tmp = tmp->next;
            }
            TreeNode *node = new TreeNode(tmp->val);
            node->left = func(head, begin , middle-1);
            node->right = func(head, middle+1, end);
            return node;
        }
        return nullptr;
    }
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == nullptr)
            return nullptr;
        int size = 0;
        ListNode *tmp = head;
        while(tmp){
            size++;
            tmp=tmp->next;
        }
        TreeNode *root = func(head, 1, size);
        return root;
    }
};

#endif //LEETCODE_109_H
