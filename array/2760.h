//
// Created by QinJM on 2023/11/16.
//

#ifndef LEETCODE_2760_H
#define LEETCODE_2760_H
#include <vector>
using namespace std;
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ret = 0;
        int tmp = 0;
        bool isEven = false;
        for(const int i : nums){
            if(i>threshold){
                ret = ret>tmp ? ret : tmp;
                tmp = 0;
                isEven = false;
            }else{
                if(i%2 == 0){
                    if(!isEven){
                        tmp++;
                        isEven = true;
                    }else{
                        ret = ret>tmp ? ret : tmp;
                        tmp = 1;
                        isEven = true;
                    }
                }else{
                    if(isEven){
                        tmp++;
                        isEven = false;
                    }else{
                        ret = ret>tmp ? ret : tmp;
                        tmp = 0;
                        isEven = false;
                    }
                }
            }
        }
        ret = ret>tmp ? ret : tmp;
        return ret;
    }
};
#endif //LEETCODE_2760_H
