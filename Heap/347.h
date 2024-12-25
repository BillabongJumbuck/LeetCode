//
// Created by QinJM on 2023/11/10.
//

#ifndef LEETCODE_347_H
#define LEETCODE_347_H
#include<vector>
using std::vector;
class Solution {
private:
    void PercDown(vector<int>& nums, int p, int n){
        int X = nums[p];
        int parent, child;

        for(parent=p;(2*parent+1)<n;parent=child){
            child = parent*2+1;
            if(child+1<n && nums[child+1]>nums[child])
                child++;
            if(X>nums[child])
                break;
            else
                nums[parent] = nums[child];
        }
        nums[parent] = X;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        for(int i=size/2-1;i>=0;--i){
            PercDown(nums, i , size);
        }

        vector<int> ret;
        for(int i=size-1;i>0 && k>0;--i){
            if(ret.empty() || nums[0] != ret[ret.size()-1]){
                ret.push_back(ret[0]);
                --k;
            }
            ret[0] = ret[i];
            PercDown(nums, 0, i);
        }
        return ret;
    }
};
#endif //LEETCODE_347_H
