//
// Created by QinJM on 2023/10/13.
//

#ifndef LEETCODE_225_H
#define LEETCODE_225_H
#include <queue>
using namespace std;
class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {

    }

    void push(int x) {
        if(q1.empty()){
            q1.push(x);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        } else if(q2.empty()){
            q2.push(x);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    int pop() {
        int a;
        if(!q1.empty()){
            a = q1.front();
            q1.pop();
        }
        else if(!q2.empty()){
            a = q2.front();
            q2.pop();
        }
        return a;
    }

    int top() {
        if(!q1.empty())
            return q1.front();
        else if(!q2.empty())
            return q2.front();
    }

    bool empty() {
        if(q1.empty() && q2.empty())
            return true;
        return false;
    }
};
#endif //LEETCODE_225_H
