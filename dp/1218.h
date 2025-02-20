//
// Created by QinJM on 24-12-31.
//

#ifndef LEETCODE_1218_H
#define LEETCODE_1218_H
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();
        int ans = 0;
        unordered_map<int, int> dp;
        for(int i : arr){
            dp[i] = dp[i - difference] + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
#endif //LEETCODE_1218_H
