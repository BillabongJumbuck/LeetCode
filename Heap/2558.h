//
// Created by QinJM on 2023/10/28.
//

#ifndef LEETCODE_2558_H
#define LEETCODE_2558_H
#include <vector>
#include <cmath>
using namespace std;
class Solution {
private:
    void BuildHeap(vector<int>& nums){
        nums.push_back(nums[nums.size()-1]);
        for(int i = nums.size()-2;i>0;--i){
            nums[i] = nums[i-1];
        }
        int size = nums.size()-1;
        for(int i=size/2;i>0;--i){
            int parent, child;
            int x = nums[i];
            for(parent = i;parent*2<=size;parent=child){
                child = parent*2;
                if((child!=size) && (nums[child] < nums[child+1]))
                    child++;
                if(x > nums[child])
                    break;
                else
                    nums[parent] = nums[child];
            }
            nums[parent] = x;
        }
    }
    void Delete(vector<int>& nums){
        nums[1] = static_cast<int>(sqrt(nums[1]));
        int x = nums[1];
        int size = nums.size()-1;
        int parent, child;
        for(parent = 1;parent*2<=size;parent=child){
            child = parent*2;
            if((child!=size) && (nums[child] < nums[child+1]))
                child++;
            if(x > nums[child])
                break;
            else
                nums[parent] = nums[child];
        }
        nums[parent] = x;
    }
public:
    long long pickGifts(vector<int>& gifts, int k) {
        BuildHeap(gifts);
        while(k>0){
            Delete(gifts);
            --k;
        }
        long long sum = 0;
        for(int i =1;i<gifts.size();++i){
            sum += gifts[i];
        }
        return sum;
    }
};
#endif //LEETCODE_2558_H
