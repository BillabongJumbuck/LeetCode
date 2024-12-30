//
// Created by QinJM on 24-12-30.
//

#ifndef LEETCODE_39_H
#define LEETCODE_39_H
#include <vector>
using namespace std;
class Solution {
    void backtrace(vector<vector<int>>& ans, vector<int> &current, vector<int>& candidates,
                   int index, int cur_sum, int target){
        if(cur_sum == target){
            ans.push_back(current);
            return;
        }
        if(cur_sum < target){
            for(int i=index+1;i<candidates.size();i++){
                int num = candidates[i];
                current.push_back(num);
                backtrace(ans, current, candidates, i, cur_sum+num, target);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrace(ans, current, candidates,0, 0, target);
        return ans;
    }
};
#endif //LEETCODE_39_H
