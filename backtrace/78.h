//
// Created by QinJM on 24-12-30.
//

#ifndef LEETCODE_78_H
#define LEETCODE_78_H
#include <vector>
using namespace std;
class Solution {
private:
    void backtrace(vector<vector<int>> &res, vector<int> &cur, vector<int>& nums, int index){
        if(index == nums.size()){
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[index]);
        backtrace(res, cur, nums, index+1);
        cur.pop_back();
        backtrace(res, cur, nums, index+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrace(res, cur, nums, 0);
        return res;
    }
};
#endif //LEETCODE_78_H
