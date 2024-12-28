//
// Created by QinJM on 24-12-26.
//

#ifndef LEETCODE_72_H
#define LEETCODE_72_H

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> dp(n+1);
        for(int i=0;i<n+1;i++){
            dp[i] = i;
        }
        int pre;
        for(int i=1;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(j==0){
                    pre = i;
                }else{
                    int case1 = dp[j]+1;
                    int case2 = pre+1;
                    int case3 = dp[j-1] + (word1[i-1] == word2[j-1] ? 0 : 1);
                    dp[j-1] = pre;
                    pre = min(min(case1, case2), case3);
                }
            }
            dp.back() = pre;
        }
        return dp.back();
    }
};

#endif //LEETCODE_72_H
