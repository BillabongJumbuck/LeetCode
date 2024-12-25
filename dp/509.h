//
// Created by QinJM on 24-12-24.
//

#ifndef LEETCODE_509_H
#define LEETCODE_509_H
class Solution {
public:
    int fib(int n) {
        if( n==0)
            return 0;
        int a=0, b=1;
        for(int i=2; i<=n; i++){
            int temp = b;
            b = a + b;
            a = temp;
        }
        return b;
    }
};
#endif //LEETCODE_509_H
