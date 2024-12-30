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
private:
    void backtrace(vector<string>& ans, string& cur, int open, int close, int n){
        if(cur.size() == n*2){
            ans.push_back(cur);
            return;
        }
        if(open < n){
            cur.push_back('(');
            backtrace(ans, cur, open+1, close, n);
            cur.pop_back();
        }
        if(close < open){
            cur.push_back(')');
            backtrace(ans, cur, open, close+1, n);
            cur.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrace(result, current, 0 , 0 ,n);
        return result;
    }
};
#endif //LEETCODE_22_H
