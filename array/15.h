//
// Created by QinJM on 2023/11/18.
//

#ifndef LEETCODE_15_H
#define LEETCODE_15_H
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> all;
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                for(int k=+1;k<size;k++){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> tmp = {nums[i], nums[j], nums[k]};
                        all.push_back(tmp);
                    }
                }
            }
        }
        return all;
    }
};
#endif //LEETCODE_15_H
