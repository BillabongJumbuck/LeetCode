//
// Created by QinJM on 24-12-24.
//

#ifndef LEETCODE_70_H
#define LEETCODE_70_H

#include<vector>

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 || n == 2)
            return n;

        std::vector<int> dp(n+1, -1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n ;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

#endif //LEETCODE_70_H
