//
// Created by QinJM on 24-12-26.
//

#ifndef LEETCODE_22_H
#define LEETCODE_22_H
#include <vector>
#include <queue>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int height = 1;
        queue<string> q;
        q.push("()");
        while(height < n){
            bool flag = true;
            int count = q.size();
            while(count > 0){
                string temp = q.front();
                q.pop();
                if(flag){
                    flag = false;
                    q.push("()" + temp);
                    q.push("(" + temp +")");
                }else{
                    q.push("()" + temp);
                    q.push("(" + temp +")");
                    q.push(temp + "()");
                }
                count--;
            }
            height++;
        }
        vector<string> res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};
#endif //LEETCODE_22_H
