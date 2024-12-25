//
// Created by QinJM on 2023/9/25.
//

#ifndef LEETCODE_66_H
#define LEETCODE_66_H
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size()-1;i>=0;--i){
            if(i==digits.size()-1)
                digits[i]++;
            if(digits[i] == 10 && i>0){
                digits[i] = 0;
                digits[i-1]++;
            }
        }
        if(digits[0] == 10){
            digits.push_back(0);
            for(int i = digits.size()-1;i>0;--i){
                digits[i]=digits[i-1];
            }
            digits[1] = 0;
            digits[0] = 1;
        }
        return digits;
    }
};
#endif //LEETCODE_66_H
