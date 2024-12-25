//
// Created by QinJM on 2023/10/18.
//

#ifndef LEETCODE_2530_H
#define LEETCODE_2530_H
#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    int ceil(int val){
        return (val+2)/3;
    }
public:
    long long maxKelements(vector<int>& nums, int k) {
        nums.push_back(nums[nums.size()-1]);
        for(int i=nums.size()-1;i>0;--i)
            nums[i] = nums[i-1];
        nums[0] = 1000000001;
        int size = nums.size()-1;
        int parent, child, elem;
        for(int i=size/2;i>0;--i){
            elem = nums[i];
            for(parent = i;parent*2<=size;parent=child){
                child = parent*2;
                if((child != size) && (nums[child]<nums[child+1]))
                    ++child;
                if(elem>=nums[child])
                    break;
                else
                    nums[parent] = nums[child];
            };
            nums[parent] = elem;
        }
        long long sum = 0;
        for(;k>0;--k){
            sum += nums[1];
            nums[1] = ceil(nums[1]);
            for(parent = 1;2*parent<=size;parent=child){
                child = parent*2;
                if((child != size) && (nums[child]<=nums[child+1]))
                    ++child;
                if(nums[parent]<=nums[child]){
                    int tmp = nums[child];
                    nums[child] = nums[parent];
                    nums[parent] = tmp;
                }
                else
                    break;
            }
        }
        return sum;
    }

    // 使用STL
    long long maxKelements_2(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        long long ans = 0;
        for(;k>0;--k){
            int x = q.top(); q.pop();
            ans += x;
            q.push((x+2/3));
        }
        return ans;
    }

};
#endif //LEETCODE_2530_H
