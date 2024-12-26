//
// Created by QinJM on 24-12-26.
//

#ifndef LEETCODE_45_H
#define LEETCODE_45_H
#include<vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> costs(size, 1e9);
        costs[0] = 0;
        for(int i=0;i<size;i++){
            int num = nums[i];
            int cost = costs[i] + 1;
            while(num > 0){
                if(i + num < size){
                    if(cost < costs[i+num]){
                        costs[i+num] = cost;
                    }
                }
                num --;
            }
        }
        return costs.back();
    }
};
#endif //LEETCODE_45_H
