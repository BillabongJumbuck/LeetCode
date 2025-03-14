//
// Created by QinJM on 24-12-28.
//

#ifndef LEETCODE_1035_H
#define LEETCODE_1035_H
#include<vector>
using namespace std;
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
#endif //LEETCODE_1035_H
