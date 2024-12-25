//
// Created by QinJM on 24-12-25.
//

#ifndef LEETCODE_63_H
#define LEETCODE_63_H
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> dp(n);
        dp[0] = (obstacleGrid[0][0] == 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                }else if(j - 1 >= 0 && obstacleGrid[i][j - 1] == 0){
                    dp[j] += dp[j-1];
                }
            }
        }
        return obstacleGrid.back().back() ? 0 : dp.back();
    }
};
#endif //LEETCODE_63_H
