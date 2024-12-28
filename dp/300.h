//
// Created by QinJM on 24-12-28.
//

#ifndef LEETCODE_300_H
#define LEETCODE_300_H
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        // dp[i]:以nums[i]结尾的最长递增子序列
        int max_length = 0;
        for(int i=0;i<n;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j] && dp[j] + 1 >dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            max_length = max(max_length, dp[i]);
        }
        return max_length;
    }
};
#endif //LEETCODE_300_H
