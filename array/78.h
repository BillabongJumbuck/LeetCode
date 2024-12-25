//
// Created by QinJM on 2023/11/29.
//

#ifndef LEETCODE_78_H
#define LEETCODE_78_H
#include <vector>
#include <iterator>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        auto begin = nums.begin();
        auto end = nums.end();
        while(begin<end){
            for(auto i = begin;i<end;i++){
                vector<int> tmp1(begin, i);
                vector<int> tmp2(i,end);
                ret.push_back(tmp1);
                ret.push_back(tmp2);
            }
            begin++;
            end--;
        }
        return ret;
    }
};
#endif //LEETCODE_78_H
