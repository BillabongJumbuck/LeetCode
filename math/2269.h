//
// Created by QinJM on 25-3-10.
//

#ifndef LEETCODE_2269_H
#define LEETCODE_2269_H
#include <cmath>

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        long long pos = pow(10, k);
        int ans = 0;
        int temp = num;
        while(temp > pos) {
            int m = temp % pos;
            if (m != 0 && num % m == 0) ans++;
            temp /= 10;
        }
        if (temp != 0 && num % temp == 0) ans++;
        return ans;
    }
};

#endif //LEETCODE_2269_H
