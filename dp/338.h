//
// Created by QinJM on 24-12-24.
//

#ifndef LEETCODE_338_H
#define LEETCODE_338_H
#include <vector>
using std::vector;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++){
            dp[i] = dp[i>>1] + (i & 1);
        }
        return dp;
    }
};

#endif //LEETCODE_338_H
