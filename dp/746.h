//
// Created by QinJM on 24-12-24.
//

#ifndef LEETCODE_746_H
#define LEETCODE_746_H
#include <vector>
using std::vector;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        for(int i=2;i<n;i++){
            dp[i] = std::min(dp[i-1]+cost[i-1], dp[i-2]+ cost[i-2]);
        }
        return std::min(dp[n-1]+cost[n-1], dp[n-2]+ cost[n-2]);
    }
};
#endif //LEETCODE_746_H
