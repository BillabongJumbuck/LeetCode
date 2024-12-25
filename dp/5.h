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
            for(int j=i+1;j<n;j++){
                if(judge(s, i, j)){
                    dp[j] = j - i + 1;
                    if(j-i+1 > len){
                        len = j-i+1;
                        m_begin = i;
                        m_end = j;
                    }
                }else{
                    dp[j] = max(dp[j], dp[j-1]);
                }
            }
        }
        return s.substr(m_begin, m_end-m_begin+1);
    }
};
#endif //LEETCODE_5_H
