//
// Created by QinJM on 2024/1/4.
//

#ifndef LEETCODE_136_H
#define LEETCODE_136_H
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(auto i : nums){
            ret = ret ^ i;
        }
        return ret;
    }
};
#endif //LEETCODE_136_H
