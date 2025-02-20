//
// Created by QinJM on 24-12-31.
//

#ifndef LEETCODE_231_H
#define LEETCODE_231_H
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        if(n==1)
            return true;

        if((n&1) == 1){
            return false;
        }else{
            return isPowerOfTwo(n >> 1);
        }
    }
};
#endif //LEETCODE_231_H
