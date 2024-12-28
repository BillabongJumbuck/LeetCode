//
// Created by QinJM on 24-12-28.
//

#ifndef LEETCODE_3046_H
#define LEETCODE_3046_H
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int num : nums){
            m[num] ++;
            if(m[num] == 3){
                return false;
            }
        }
        return true;
    }
};
#endif //LEETCODE_3046_H
