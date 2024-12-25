//
// Created by QinJM on 2023/12/3.
//

#ifndef LEETCODE_1423_H
#define LEETCODE_1423_H
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    struct node{
        int head;
        int tail;
        int _k;
        int sum;
        node() = default;
        node(int a, int b, int c, int d) : head(a), tail(b), _k(c), sum(d) {}
    };
    struct cmp{
        bool operator()(node* a, node* b) const{
            return a->sum < b->sum;
        }
    };
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if (cardPoints.size() == 1)
            return cardPoints[0];

        priority_queue<node*, vector<node*>, cmp> q;
        int begin = 0, end = cardPoints.size() - 1;
        q.push(new node(begin+1, end, k-1, cardPoints[0]));
        q.push(new node(begin, end-1, k-1, cardPoints[0]));
        int ret = -1;
        while(ret == -1){
            node* now = q.top(); q.pop();
            vector<node*> v{now};
            while( !q.empty() && q.top()->sum == now->sum){
                v.push_back(q.top());
                q.pop();
            }
            for(auto i : v){
                if(i->_k == 0){
                    ret = i->sum;
                    break;
                }
                if(cardPoints[i->tail] != cardPoints[i->head]){
                    q.push(new node(i->head+1, i->tail, i->_k-1, i->sum+cardPoints[i->head]));
                    q.push(new node(i->head, i->tail-1, i->_k-1, i->sum+cardPoints[i->tail]));
                }else{
                    if(i->_k == 1){
                        q.push(new node(i->head+1, i->tail, i->_k-1, i->sum+cardPoints[i->head]));
                    }else{
                        node *a = new node(i->head+1, i->tail, i->_k-1, i->sum+cardPoints[i->head]);
                        node *b = new node(i->head, i->tail-1, i->_k-1, i->sum+cardPoints[i->tail]);
                        q.push(new node(a->head+1, a->tail, a->_k-1, a->sum+cardPoints[i->head]));
                        q.push(new node(a->head, a->tail-1, a->_k-1, a->sum+cardPoints[i->tail]));
                        q.push(new node(b->head+1, b->tail, b->_k-1, b->sum+cardPoints[i->head]));
                        q.push(new node(b->head, b->tail-1, b->_k-1, b->sum+cardPoints[i->tail]));
                    }
                }
            }
        }
        return ret;
    }
};
#endif //LEETCODE_1423_H
