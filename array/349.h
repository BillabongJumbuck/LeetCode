//
// Created by QinJM on 2023/12/12.
//

#ifndef LEETCODE_349_H
#define LEETCODE_349_H
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(auto i: nums1){
            for(auto j : nums2){
                if(i == j && find(ans.begin(), ans.end(), i) == ans.end()){
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
#endif //LEETCODE_349_H
