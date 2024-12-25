//
// Created by QinJM on 2023/10/19.
//

#ifndef LEETCODE_96_H
#define LEETCODE_96_H
class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 1;
        if( n == 1 || n == 2)
            return n;
        int sum = 0;
        n-=1;
        for(int i = 0; i<=n; ++i){
            sum+= numTrees(i) * numTrees(n-i);
        }
        return sum;
    }
};
#endif //LEETCODE_96_H
