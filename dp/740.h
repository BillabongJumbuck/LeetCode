//
// Created by QinJM on 24-12-27.
//

#ifndef LEETCODE_740_H
#define LEETCODE_740_H

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> nums_map;
        int min_num = 1e9;
        int max_num = 0;
        for(int num: nums){
            nums_map[num]++;
            min_num = min(min_num, num);
            max_num = max(max_num, num);
        }
        int a = min_num * nums_map[min_num];
        int b = max(a, (min_num+1) * nums_map[min_num+1]);
        for(int i=min_num+2;i<=max_num;i++){
            int temp = b;
            b = max(b, a + i * nums_map[i]);
            a = temp;
        }
        return b;
    }
};
#endif //LEETCODE_740_H
