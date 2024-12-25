//
// Created by QinJM on 2023/12/17.
//

#ifndef LEETCODE_27_H
#define LEETCODE_27_H
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int j=0;
        while(j<nums.size()){
            if(nums[j] == val){
                j++;
            }else{
                nums[i] = nums[j];
                i++;
                j++;
            }
        }
        return i;
    }
};
#endif //LEETCODE_27_H
