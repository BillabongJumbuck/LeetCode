//
// Created by QinJM on 2023/12/10.
//

#ifndef LEETCODE_231210_03_H
#define LEETCODE_231210_03_H
#include <vector>
#include <cmath>
using namespace std;
class Solution {
private:
    int func(vector<int>& v, int begin, int end, int x){
        int ret = 0;
        for(int i=begin;i<end;i++){
            if(v[i] == x)
                ret++;
        }
        return ret;
    }
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max = nums[i];
                count = 1;
            }else if(nums[i] == max){
                count++;
            }
        }
        int size = nums.size();
        int ans = 0;
        if(k<=count){
            int i=0;
            int j=size;
            while(i<j){
                for(int a=i;k<j-1;k++){
                    if(func(nums,i,a,max) >= k)
                        ans++;
                    if(func(nums,a,j,max) >= k)
                        ans++;
                }
                i++;
                j--;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_231210_03_H
