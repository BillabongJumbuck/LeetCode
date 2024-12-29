//
// Created by QinJM on 24-12-29.
//

#ifndef LEETCODE_50_H
#define LEETCODE_50_H
class Solution {
private:
    double pow_iter(double x, int n, double res){
        return n == 0 ? res :
                n%2 ? pow_iter(x, n-1, res + x)
                 : pow_iter(x * x, n/2, res);
    }
public:
    double myPow(double x, int n) {
        return pow_iter(x, n, 0);
    }
};
#endif //LEETCODE_50_H
