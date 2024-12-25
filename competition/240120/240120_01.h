//
// Created by QinJM on 2024/1/20.
//

#ifndef LEETCODE_240120_01_H
#define LEETCODE_240120_01_H
#include <vector>
using namespace std;
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1 = 50;
        int min2 = 50;
        for(int i=1;i<nums.size();i++){
            if(nums[i] <= min1){
                min2 = min1;
                min1 = nums[i];
            }else if(nums[i] <= min2){
                min2 = nums[i];
            }
        }
        return nums[0] + min1 + min2;
    }
};
#endif //LEETCODE_240120_01_H
