//
// Created by QinJM on 2023/10/14.
//

#ifndef LEETCODE_232_H
#define LEETCODE_232_H
#include <stack>
using namespace std;
class MyQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    MyQueue() {

    }

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int val = 0;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        val = s2.top();
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return val;
    }

    int peek() {
        int val = 0;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        val = s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return val;
    }

    bool empty() {
        return s1.empty();
    }
};
#endif //LEETCODE_232_H
