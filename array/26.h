//
// Created by QinJM on 2023/11/10.
//

#ifndef LEETCODE_26_H
#define LEETCODE_26_H
#include <vector>
using std::vector;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[i] == nums[j]){
                j++;
                continue;
            }
            i++;
            nums[i] = nums[j];
        }
        return i+1;
    }
};
#endif //LEETCODE_26_H
