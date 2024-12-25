//
// Created by QinJM on 24-12-25.
//

#ifndef LEETCODE_64_H
#define LEETCODE_64_H
#include <vector>
using std::vector;
using std::min;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n);
        dp[0] = grid[0][0];
        for(int j=1;j<n;j++){
            dp[j] = grid[0][j] + dp[j-1];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j == 0){
                    dp[j] += grid[i][j];
                }else{
                    dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
                }
            }
        }
        return dp.back();
    }
};
#endif //LEETCODE_64_H
