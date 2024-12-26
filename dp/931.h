//
// Created by QinJM on 24-12-26.
//

#ifndef LEETCODE_931_H
#define LEETCODE_931_H
#include <vector>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        vector<int> dp(n);
        for(int i=0;i<n;i++){
            dp[i] = matrix[0][i];
        }
        int pre = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j == 0){
                    pre = dp[j];
                    dp[j] = min(dp[j], dp[j+1]) + matrix[i][j];
                }else if( j== n-1){
                    dp[j] = min(pre, dp[j]) + matrix[i][j];
                }else{
                    int temp = min(pre, min(dp[j], dp[j+1])) + matrix[i][j];
                    pre = dp[j];
                    dp[j] = temp;
                }
            }
        }
        int min_cost = 1e9;
        for(int i : dp){
            min_cost = min(min_cost, i);
        }
        return min_cost;
    }
};
#endif //LEETCODE_931_H
