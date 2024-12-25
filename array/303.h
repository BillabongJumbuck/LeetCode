//
// Created by QinJM on 2023/11/16.
//

#ifndef LEETCODE_303_H
#define LEETCODE_303_H
#include<vector>
using namespace std;
class NumArray {
    vector<int> myvec;
public:
    NumArray(vector<int>& nums) {
        myvec.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
            myvec.push_back(myvec[i-1]+nums[i]);
    }

    int sumRange(int left, int right) {
        if(left == 0)
            return myvec[right];
        else
            return myvec[right] - myvec[left-1];
    }
};
#endif //LEETCODE_303_H
