//
// Created by QinJM on 24-12-26.
//

#ifndef LEETCODE_120_H
#define LEETCODE_120_H
#include<vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=triangle[i].size()-1;j>=0;j--){
                if(j == 0){
                    dp[j] = dp[j] + triangle[i][j];
                }else if(j == triangle[i].size()-1){
                    dp[j] = dp[j-1] + triangle[i][j];
                }else{
                    dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
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
#endif //LEETCODE_120_H
