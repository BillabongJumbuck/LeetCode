//
// Created by QinJM on 2023/11/10.
//

#ifndef LEETCODE_703_H
#define LEETCODE_703_H
#include<vector>
using std::vector;
class KthLargest {
private:
    vector<int> mynums;
    int k;
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
    KthLargest(int k, vector<int>& nums) {
        this->mynums = nums;
        this->k = k;

        int size = mynums.size();
        for(int i=size/2-1;i>=0;--i){
            PercDown(mynums, i , size);
        }

        for(int i=size-1;i>0;--i){
            Swap(&mynums[0], &mynums[i]);
            PercDown(mynums, 0 ,i);
        }
    }

    int add(int val) {
        int i=0;
        for(;i<mynums.size();++i){
            if(mynums[i]>val)
                break;
        }
        if(i==mynums.size())
            mynums.push_back(val);
        else
            mynums.insert(mynums.begin()+i,val);

        return mynums[mynums.size()-k];
    }
};
#endif //LEETCODE_703_H
