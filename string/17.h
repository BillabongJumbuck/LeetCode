//
// Created by QinJM on 2023/12/8.
//

#ifndef LEETCODE_17_H
#define LEETCODE_17_H
#include <vector>
#include <string>
using namespace std;
class Solution {
    vector<string> Cartesian(vector<string>& a, vector<string>& b){
        vector<string> ret;
        for(auto i : a){
            for(auto j : b){
                ret.push_back(i + j);
            }
        }
        return ret;
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<string>> m(10);
        m[2] = {"a", "b","c"};
        m[3] = {"d", "e", "f"};
        m[4] = {"g", "h", "i"};
        m[5] = {"j", "k", "l"};
        m[6] = {"m", "n", "o"};
        m[7] = {"p", "q", "r", "s"};
        m[8] = {"t", "u", "v"};
        m[9] = {"w", "x", "y", "z"};
        vector<string> ans;
        for(int i=0;i<digits.size();i++){
            if(i == 0) {
                ans = m[digits[i] - '0'];
            }else{
                ans = Cartesian(ans, m[digits[i] - '0']);
            }
        }
        return ans;
    }
};
#endif //LEETCODE_17_H
