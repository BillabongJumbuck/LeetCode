//
// Created by QinJM on 24-12-24.
//

#ifndef LEETCODE_1137_H
#define LEETCODE_1137_H
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;

        int a = 0, b = 1, c = 1;
        for(int i=3;i<=n;i++){
            int temp = c;
            c = a + b + c;
            a = b;
            b = temp;
        }
        return c;
    }
};
#endif //LEETCODE_1137_H
