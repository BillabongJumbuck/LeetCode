//
// Created by QinJM on 24-12-29.
//

#ifndef LEETCODE_50_H
#define LEETCODE_50_H

#include <climits>

class Solution {
private:
    double pow_iter(double x, int n, double res){
        if(n == 0){
            return res;
        }
        if(n%2){
            return pow_iter(x, n-1, res * x);
        }else{
            return pow_iter(x * x, n/2, res);
        }
    }
public:
    double myPow(double x, int n) {
        if(n == 0){
            return 1;
        }else if(x == 1){
            return x;
        }else if(n > 0){
            return pow_iter(x, n, 1);
        }else if(n == INT_MIN){
            return 1/(pow_iter(x, -(n+1), 1) * x);
        }
        else{
            return 1/pow_iter(x, -n, 1);
        }
    }
};
#endif //LEETCODE_50_H
