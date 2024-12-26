//
// Created by QinJM on 24-12-26.
//

#ifndef LEETCODE_1289_H
#define LEETCODE_1289_H
#include <vector>
using namespace std;
class Solution {
private:
    int find_min(vector<int>& v, int x){
        int ret = 1e9;
        for(int i=0;i<v.size();i++){
            if(i != x){
                ret = min(ret, v[i]);
            }
        }
        return ret;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<int> dp(n);
        vector<int> help(n);
        for(int i=0;i<n;i++){
            dp[i] = grid[0][i];
        }
        help = dp;
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                dp[j] = find_min(help, j) + grid[i][j];
            }
            help = dp;
        }
        return find_min(dp, -1);
    }
};
#endif //LEETCODE_1289_H
