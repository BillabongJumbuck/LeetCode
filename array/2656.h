//
// Created by QinJM on 2023/11/15.
//

#ifndef LEETCODE_2656_H
#define LEETCODE_2656_H

#include <vector>
using namespace std;
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max)
                max = nums[i];
        }
        int ret=0;
        while(k>0){
            ret += max;
            max++;
            k--;
        }
        return ret;
    }
};
#endif //LEETCODE_2656_H
