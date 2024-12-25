//
// Created by QinJM on 2023/10/29.
//

#ifndef LEETCODE_231029_01_H
#define LEETCODE_231029_01_H
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ret = 0;
        for(int i=0;i<31;++i){
            int count = 0;
            int tmp = static_cast<int>(pow(2,i));
            for(int j=0;j<nums.size();++j){
                if((nums[j] & tmp) == tmp)
                    count++;
            }
            if(count>=k)
                ret += tmp;
        }
        return ret;
    }
};
#endif //LEETCODE_231029_01_H
