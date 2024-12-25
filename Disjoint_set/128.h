//
// Created by QinJM on 2023/11/24.
//

#ifndef LEETCODE_128_H
#define LEETCODE_128_H
#include <vector>
using namespace std;
class Solution {
private:
    void PercDown(vector<int>& nums, int p, int n){
        int Parent = p, Child;
        int x = nums[Parent];
        for(;Parent*2+2<=n;Parent = Child){
            Child = Parent*2+1;
            if(Child+1<=n && nums[Child+1]>nums[Child])
                Child++;
            if(nums[Parent]>=nums[Child])
                break;
            else
                nums[Parent] = nums[Child];
        }
        nums[Parent] = x;
    }
    void Swap(int *a, int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size()-1;
        for(int i=(n-1)/2;i>=0;i--){
            PercDown(nums, i, n);
        }

        for(int i = n;i>0;i--){
            Swap(&nums[i], &nums[0]);
            PercDown(nums, i, i);
        }
    }
};
#endif //LEETCODE_128_H
