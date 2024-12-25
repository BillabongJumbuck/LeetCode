//
// Created by QinJM on 2023/11/6.
//
#ifndef LEETCODE_133_H
#define LEETCODE_133_H
#include <vector>
#include <algorithm>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    void dfs(Node *node, Node *mynode, vector<int> &isVisited, vector<Node*> &isCreted){
        if(find(isVisited.begin(), isVisited.end(), node->val) == isVisited.end()){
            isVisited.push_back(node->val);
            for(Node* i : node->neighbors){
                if(find_if(isCreted.begin(), isCreted.end(), [i](Node* x) -> bool{ return x->val == i->val; }) == isCreted.end()){
                    Node *tmp = new Node(i->val);
                    mynode->neighbors.push_back(tmp);
                    isCreted.push_back(tmp);
                }else{
                    auto tmp  =find_if(isCreted.begin(), isCreted.end(), [i](Node* x) -> bool{ return x->val == i->val; });
                    mynode->neighbors.push_back(*tmp);
                }
            }
            for(int i = 0;i<node->neighbors.size();i++){
                if(find(isVisited.begin(), isVisited.end(), node->neighbors[i]->val) == isVisited.end())
                    dfs(node->neighbors[i], mynode->neighbors[i], isVisited, isCreted);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        vector<int> isVisited;
        vector<Node*> isCreted;
        Node *mynode = new Node(node->val);
        isCreted.push_back(mynode);
        dfs(node, mynode, isVisited, isCreted);
        return mynode;
    }
};

#endif //LEETCODE_133_H
