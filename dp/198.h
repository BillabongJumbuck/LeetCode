//
// Created by QinJM on 24-12-26.
//

#ifndef LEETCODE_198_H
#define LEETCODE_198_H
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int n = nums.size();
        int a = nums[0];
        int b = max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            int temp = b;
            b = max(a + nums[i], b);
            a = temp;
        }
        return b;
    }
};
#endif //LEETCODE_198_H
