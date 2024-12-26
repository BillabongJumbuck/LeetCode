//
// Created by QinJM on 24-12-27.
//

#ifndef LEETCODE_3159_H
#define LEETCODE_3159_H
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        vector<int> x_nums;
        for(int i=0;i<n;i++){
            if(nums[i] == x){
                x_nums.push_back(i);
            }
        }
        vector<int> ret;
        ret.reserve(queries.size());
        for(int q: queries){
            if(q>x_nums.size()){
                ret.push_back(-1);
            }else{
                ret.push_back(x_nums[q-1]);
            }
        }
        return ret;
    }
};
#endif //LEETCODE_3159_H
