//
// Created by QinJM on 2023/10/19.
//

#ifndef LEETCODE_96_H
#define LEETCODE_96_H
#include <vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2;i<n+1;i++){
            for(int j=0;j<i;j++){
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp.back();
    }
};
#endif //LEETCODE_96_H
