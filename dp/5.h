//
// Created by QinJM on 24-12-25.
//

#ifndef LEETCODE_5_H
#define LEETCODE_5_H
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = 0;
        int m_begin =0, m_end = 0;
        vector<int> dp(n, 1);
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>i;j--){
                if(s[i] == s[j] && dp[j-1] == 1){
                    dp[j] = 1;
                    if(j-i+1>max_len){
                        max_len = j-i+1;
                        m_begin=i;
                        m_end=j;
                    }
                }else{
                    dp[j] = 0;
                }
            }
        }
        return s.substr(m_begin, m_end-m_begin+1);
    }
};
#endif //LEETCODE_5_H
