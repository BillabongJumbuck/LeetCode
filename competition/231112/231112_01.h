//
// Created by QinJM on 2023/11/12.
//

#ifndef LEETCODE_231112_01_H
#define LEETCODE_231112_01_H
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        priority_queue<int, vector<int>, less<>> q;
        for(int i=0;i<nums.size();++i){
            for(int j=i;j<nums.size();++j){
                if(abs(nums[i]-nums[j])<= min(nums[i], nums[j]))
                    q.push(nums[i]^nums[j]);
            }
        }
        return q.top();
    }
};
#endif //LEETCODE_231112_01_H
