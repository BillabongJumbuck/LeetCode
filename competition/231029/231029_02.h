//
// Created by QinJM on 2023/10/29.
//

#ifndef LEETCODE_231029_02_H
#define LEETCODE_231029_02_H
#include <vector>
#include <cmath>
using namespace std;
class Solution {
        private:
        inline long long max(long long a, long long b){
            if(a>b)
                return a;
            else
                return b;
        }
        public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
            if(nums1.empty() || nums2.empty())
                return -1;
            int count1 = 0, count2 = 0;
            long long sum1 = 0, sum2 = 0;
            for(int a = 0;a<nums1.size();++a){
                if(nums1[a] == 0)
                    count1++;
                else
                    sum1 += nums1[a];
            }
            for(int b = 0;b<nums2.size();++b){
                if(nums2[b] == 0)
                    count2++;
                else
                    sum2 += nums2[b];
            }
            if(count1 && count2){
                return max(count1+sum1, count2+sum2);
            }else if((count1==0) && (count2==0)){
                if(sum1 == sum2)
                    return sum1;
                else return -1;
            }else if(count1){
                if(sum1 + count1 > sum2)
                    return -1;
                else
                    return sum2;
            }else{
                if(sum2 + count2 > sum1)
                    return -1;
                else
                    return sum1;
            }
        }
};
#endif //LEETCODE_231029_02_H
