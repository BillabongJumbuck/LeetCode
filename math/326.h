//
// Created by QinJM on 24-12-31.
//

#ifndef LEETCODE_326_H
#define LEETCODE_326_H
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0)
            return false;
        if(n == 1)
            return true;
        if(n % 3 !=0)
            return false;
        else
            return isPowerOfThree(n/3);
    }
};
#endif //LEETCODE_326_H
