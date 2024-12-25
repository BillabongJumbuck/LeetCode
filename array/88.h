//
// Created by QinJM on 2023/11/13.
//

#ifndef LEETCODE_88_H
#define LEETCODE_88_H
#include <vector>
using namespace std;
class Solution {
private:
    void PercDown(vector<int>& nums, int p, int n){
        int X = nums[p];
        int parent, child;

        for(parent=p;(2*parent+1)<n;parent=child){
            child = parent*2+1;
            if(child+1<n && nums[child+1]<nums[child])
                child++;
            if(X<nums[child])
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i!=n;++i){
            nums1[m+i] = nums2[i];
        }
        int size = nums1.size();
        for(int i=size/2-1;i>=0;--i){
            PercDown(nums1, i , size);
        }

        for(int i = size-1;i>0;i--){
            Swap(&nums1[0], &nums1[i]);
            PercDown(nums1, 0 ,i);
        }
    }
};
#endif //LEETCODE_88_H
