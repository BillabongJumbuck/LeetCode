//
// Created by QinJM on 24-12-30.
//

#ifndef LEETCODE_518_H
#define LEETCODE_518_H
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        std::sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n+1));
        for(int j=0;j<n+1;j++){
            dp[0][j] = 1;
        }
        // i : amount j:coins
        for(int i=1;i<amount+1;i++){
            for(int j=1;j<n+1;j++){
                int coin = coins[j-1];
                if(i < coin){
                    // 不能选coin
                    dp[i][j] = dp[i][j-1];
                }else{
                    // 选coin
                    int case1 = dp[i-coin][j];
                    // 不选coin
                    int case2 = dp[i][j-1];
                    dp[i][j] = case1 + case2;
                }
            }
        }
        return dp[amount][n];
    }
};
#endif //LEETCODE_518_H
