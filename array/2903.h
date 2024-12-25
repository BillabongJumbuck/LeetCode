//
// Created by QinJM on 2023/10/21.
//

#ifndef LEETCODE_2903_H
#define LEETCODE_2903_H
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> ans  = {-1,-1};
        for(int i=0;i+indexDifference<nums.size();++i){
            for(int j=i+indexDifference;j<nums.size();++j){
                if(abs(nums[i]-nums[j]) >= valueDifference){
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_2903_H
