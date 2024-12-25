//
// Created by QinJM on 2024/1/16.
//

#ifndef LEETCODE_297_H
#define LEETCODE_297_H
#include <string>
#include <stack>
using std::string;
using std::stack;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Codec {
private:
    stack<TreeNode*> stk;
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data;
        stack<TreeNode*> stk;
        while(!stk.empty() || root){
            while(root){
                data += std::to_string(root->val) + ' ';
                stk.push(root);
                root = root->left;
            }
            data += "#";
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *head = nullptr;
        TreeNode *cur = nullptr;
        for(int i=0;i<data.size();i++){
            if(data[i]== ' '){
                continue;
            }else if(data[i] == '#'){
                cur = stk.top();
                stk.pop();
                cur->right = deserialize(data.substr(i+1, data.size() - i));
                break;
            }else{
                bool isNegative = false;
                if(data[i] == '-'){
                    isNegative = true;
                    i++;
                }
                int val = static_cast<int>(data[i] - '0');
                while(i+1<data.size() && '0'<=data[i+1] && data[i+1]<='9'){
                    i++;
                    val = 10*val + static_cast<int>(data[i] - '0');
                }
                if(isNegative){
                    val = 0 - val;
                }
                TreeNode *tmp = new TreeNode(val);
                if(head == nullptr){
                    head = tmp;
                    cur = tmp;
                }else{
                    cur->left = tmp;
                    cur = tmp;
                }
                stk.push(cur);
            }
        }
        return head;
    }
};
#endif //LEETCODE_297_H
