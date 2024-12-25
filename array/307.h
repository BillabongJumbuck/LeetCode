//
// Created by QinJM on 2023/11/13.
//

#ifndef LEETCODE_307_H
#define LEETCODE_307_H
#include <vector>
using namespace std;
class NumArray {
    vector<int> num;
public:
    NumArray(vector<int>& nums) {
        num = nums;
    }

    void update(int index, int val) {
        num[index] = val;
    }

    int sumRange(int left, int right) {
        int sum = 0;
        for(int i=left;i<=right;++i)
            sum+=num[i];
        return sum;
    }
};
#endif //LEETCODE_307_H
