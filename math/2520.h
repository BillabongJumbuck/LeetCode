//
// Created by QinJM on 2023/10/26.
//

#ifndef LEETCODE_2520_H
#define LEETCODE_2520_H
class Solution {
public:
    int countDigits(int num) {
        int a = num, b=0;
        int count = 0;
        while(a>0){
            b = a%10;
            a = a/10;
            if(num%b == 0)
                count++;
        }
        return count;
    }
};
#endif //LEETCODE_2520_H
