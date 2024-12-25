//
// Created by QinJM on 2024/1/18.
//

#ifndef LEETCODE_503_H
#define LEETCODE_503_H
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int max_value = INT_MIN;
        int max_index = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] > max_value){
                max_value = nums[i];
                max_index = i;
            }
        }

        stack<int> stk;
        stack<int> tmp;
        stk.push(max_value);
        tmp.push(-1);

        for(int i=0;i<nums.size();i++){
            while(!stk.empty() && stk.top()<=nums[(max_index-i+nums.size())%nums.size()]){
                stk.pop();
            }
            int a = stk.empty() ? -1 : stk.top();
            tmp.push(a);
            stk.push(nums[(max_index-i+nums.size())%nums.size()]);
        }
        vector<int> ans(nums.size(), -1);
        for(int i=0;i<nums.size();i++){
            ans[(max_index+1+i) % nums.size()] = tmp.top();
            tmp.pop();
        }
        return ans;
    }
};
#endif //LEETCODE_503_H
