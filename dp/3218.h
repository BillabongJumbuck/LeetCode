//
// Created by QinJM on 24-12-25.
//

#ifndef LEETCODE_3218_H
#define LEETCODE_3218_H
#include <utility>
#include<vector>
#include<queue>
using std::vector;
using std::queue;
using std::priority_queue;
class Solution {
private:
    struct Cake{
        int l;
        int r;
        int t;
        int b;
    };
    struct Node{
        vector<Cake> cakes;
        int cost;
        int predict;
        Node(Node* node){
            cakes = node->cakes;
            cost = node->cost;
            predict = node->predict;
        }
        Node(vector<Cake> v, int c) : cakes(std::move(v)), cost(c), predict(0){}
    };
    bool is1x1(Cake cake){
        return cake.l == cake.r && cake.t == cake.b;
    }
    class cmp{
    public:
        bool operator()(Node* node1, Node* node2){
            return node1->cost < node2->cost;
        }
    };
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        Cake cake = {0, n-1, 0, m-1};
        if(is1x1(cake)){
            return 0;
        }
        Node *root = new Node{vector<Cake>{cake}, 0};
        int min_cost = 1e9;

        priority_queue<Node*, vector<Node*>, cmp> q;
        q.push(root);
        while(!q.empty()){
            Node *node = q.top();
            q.pop();
            if(node->cakes.empty()){
                if(node->cost < min_cost)
                    min_cost = node->cost;
                break;
            }
            Cake temp = node->cakes.back();
            node->cakes.pop_back();
            for(int i=temp.l; i<temp.r;i++){
                Cake cake1 = {temp.l,i, temp.t, temp.b};
                Cake cake2 = {i+1, temp.r, temp.t, temp.b};
                Node *node_new = new Node(node);
                node_new->cost += verticalCut[i];
                if(!is1x1(cake1)){
                    node_new->cakes.push_back(cake1);
                }
                if(!is1x1(cake2)){
                    node_new->cakes.push_back(cake2);
                }
                node->predict = node->cost + node->cakes.size();
                q.push(node_new);
            }
            for(int i=temp.t; i<temp.b;i++){
                Cake cake1 = {temp.l, temp.r, temp.t, i};
                Cake cake2 = {temp.l, temp.r, i+1, temp.b};
                Node *node_new = new Node(node);
                node_new->cost += horizontalCut[i];
                if(!is1x1(cake1)){
                    node_new->cakes.push_back(cake1);
                }
                if(!is1x1(cake2)){
                    node_new->cakes.push_back(cake2);
                }
                node->predict = node->cost + node->cakes.size();
                q.push(node_new);
            }
        }
        return min_cost;
    }
};

#endif //LEETCODE_3218_H
