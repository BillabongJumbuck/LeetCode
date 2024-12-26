//
// Created by QinJM on 24-12-26.
//

#ifndef LEETCODE_53_H
#define LEETCODE_53_H
#include<vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = nums[0];
        int res = nums[0];
        for(int i=1;i<nums.size();i++){
            pre = max(pre + nums[i], nums[i]);
            res = max(pre, res);
        }
        return res;
    }
};
#endif //LEETCODE_53_H
