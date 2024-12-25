//
// Created by QinJM on 2024/1/18.
//

#ifndef LEETCODE_496_H
#define LEETCODE_496_H
#include <stack>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        map<int, int> m;
        int i = nums2.size();
        while(i>=0){
            if(stk.empty()){
                m[nums2[i]] = -1;
                stk.push(nums2[i]);
                i--;
            }else if(stk.top() > nums2[i]){
                m[nums2[i]] = stk.top();
                stk.push(nums2[i]);
                i--;
            }else{
                stk.pop();
            }
        }
        vector<int> ans;
        ans.reserve(nums1.size());
        for(const auto& i : nums1){
            ans.push_back(m[i]);
        }
        return ans;
    }
};
#endif //LEETCODE_496_H
