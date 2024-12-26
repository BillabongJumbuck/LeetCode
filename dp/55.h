//
// Created by QinJM on 24-12-26.
//

#ifndef LEETCODE_55_H
#define LEETCODE_55_H
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = nums.front();
        for(int i=0;i<nums.size()-1;i++){
            step--;
            if(nums[i] > step){
                step = nums[i];
            }
            if(step == 0)
                return false;
        }
        return true;
    }
};

#endif //LEETCODE_55_H
