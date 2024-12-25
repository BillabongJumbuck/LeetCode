//
// Created by QinJM on 2023/10/19.
//

#ifndef LEETCODE_1480_H
#define LEETCODE_1480_H
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i=1;i<nums.size();++i){
            nums[i] = nums[i] + nums[i-1];
        }
        return nums;
    }
};
#endif //LEETCODE_1480_H
