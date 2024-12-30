//
// Created by QinJM on 24-12-30.
//

#ifndef LEETCODE_646_H
#define LEETCODE_646_H
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        std::sort(pairs.begin(), pairs.end(), [](vector<int>& p1, vector<int>& p2) -> bool {
            if(p1[0] != p2[0]){
                return p1[0] < p2[0];
            } else {
                return p1[1] < p2[1];
            }
        });
        int size = pairs.size();
        vector<int> dp(size);
        dp[0] = 1;
        for(int i=1;i<size;i++){
            dp[i] = 1;
            vector<int>& pair = pairs[i];
            for(int j=0;j<i;j++){
                if(pair[0] > pairs[j][1]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[size-1];
    }
};
#endif //LEETCODE_646_H
