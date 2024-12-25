
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
    int maxDepth(TreeNode* root) {
        if(root== nullptr)
            return 0;
        queue<TreeNode*> q;
        int deep = 0, s;
        q.push(root);
        while(!q.empty()){
            s=q.size();
            while(s>0){
                root=q.front();
                q.pop();
                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);
                --s;
            }
            ++deep;
        }
        return deep;
    }
};