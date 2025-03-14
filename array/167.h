//
// Created by QinJM on 2024/1/13.
//

#ifndef LEETCODE_167_H
#define LEETCODE_167_H
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i=0, j = numbers.size()-1;
        while(i<=j){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                ans.push_back(i+1);
                ans.push_back(j-1);
                break;
            }else if(sum < target){
                i++;
            }else if(sum > target){
                j--;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_167_H
