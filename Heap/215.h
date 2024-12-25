//
// Created by QinJM on 2023/10/31.
//

#ifndef LEETCODE_215_H
#define LEETCODE_215_H
#include <vector>
using namespace std;
class Solution {
private:
    void PercDown(vector<int> &nums, int root, int n){
        int X;
        int parent, child;

        X=nums[root];
        for(parent=root;(parent*2+1)<n;parent=child){
            child = parent*2+1;
            if(child!=n-1 && nums[child]<nums[child+1])
                child++;
            if(X>nums[child])
                break;
            else
                nums[parent] = nums[child];
        }
        nums[parent] = X;
    }
    void Swap(int *a, int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();

        for(int i=size/2-1;i>=0;i--)
            PercDown(nums, i, size);
        k--;
        for(int i = size-1;k>0;--i,--k){
            Swap(&nums[0], &nums[i]);
            PercDown(nums, 0 , i);
        }
        return nums[0];
    }
};
#endif //LEETCODE_215_H
