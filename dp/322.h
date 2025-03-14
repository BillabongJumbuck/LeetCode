//
// Created by QinJM on 24-12-29.
//

#ifndef LEETCODE_322_H
#define LEETCODE_322_H
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::sort(coins.begin(), coins.end());
        int n = coins.size();
        vector<vector<int>> dp(amount+1, vector<int>(n+1));
        // i : amount j:coins
        for(int i=0;i<amount+1;i++){
            dp[i][0] = 1e9;
        }
        for(int i=1;i<amount+1;i++){
            for(int j=1;j<n+1;j++){
                int coin = coins[j-1];
                if(i < coin){
                    // 不能选coin
                    dp[i][j] = dp[i][j-1];
                }else{
                    // 选coin
                    int case1 = dp[i-coin][j] + 1;
                    // 不选coin
                    int case2 = dp[i][j-1];
                    dp[i][j] = min(case1, case2);
                }
            }
        }
        return dp[amount][n] == 1e9 ?  -1  : dp[amount][n];
    }
};
#endif //LEETCODE_322_H
