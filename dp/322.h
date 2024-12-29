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
        int n = coins.size()+1;
        vector<vector<int>> dp(amount+1, vector<int>(n));
        // i : amount j:coins
        for(int i=1;i<amount+1;i++){
            for(int j=1;j<n+1;j++){
                int coin = coins[j-1];
                if(i < coin){
                    // 不能选coin
                    dp[i][j] = dp[i][j-1];
                }else{
                    // 选coin
                    int case1 = dp[i-coin][j] + 1;
                    int case2 =
                }
                int case1 = i-coin < 0 ? 0 : dp[i-coin][j] + 1;
                int case2 = dp[i][j-1];
            }
        }
    }
};
#endif //LEETCODE_322_H
