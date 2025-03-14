//
// Created by QinJM on 2024/1/19.
//

#ifndef LEETCODE_7_H
#define LEETCODE_7_H
#include <cmath>
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while( x!= 0){
            if(rev<INT_MIN/10 || rev>INT_MAX/10){
                return 0;
            }
            int digit = x % 10;
            x /= 10;
            rev = rev * 10 + digit;
        }
        return rev;
    }
};
#endif //LEETCODE_7_H
