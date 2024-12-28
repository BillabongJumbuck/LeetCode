//
// Created by QinJM on 24-12-28.
//

#ifndef LEETCODE_139_H
#define LEETCODE_139_H
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    bool match(string& s, int begin, string& word){
        for(int i=0;i<word.size();i++){
            if(begin+i > s.size() || word[i] != s[begin+i]){
                return false;
            }
        }
        return true;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int end = s.size();
        vector<int> dp(end);
        for(int i=0;i<end;i++){
            if(i == 0 || dp[i-1] == 1){
                for(string& word : wordDict){
                    if(match(s, i, word)){
                        dp[i+word.size()-1] = 1;
                    }
                }
            }
        }
        return dp.back() == 1;
    }
};
#endif //LEETCODE_139_H
