//
// Created by QinJM on 24-8-19.
//

#ifndef LEETCODE_69_H
#define LEETCODE_69_H

class Solution {
public:
    int mySqrt(int x) {
        return sqrt_iter(1.0, x);
    }
private:
    int sqrt_iter(double guess, int x){
        if(good_enough(guess, x))
            return static_cast<int>(guess);
        else
            return sqrt_iter(improve(guess, x), x);
    }

    double abs(double number){
        return number < 0 ? (0 - number) : number;
    }

    bool good_enough(double guess, int x){
        if(abs(guess * guess - x) < 0.0001)
            return true;
        return false;
    }

    double improve(double guess, int x){
        return (guess + (x / guess)) / 2;
    }
};

#endif //LEETCODE_69_H
