//
// Created by QinJM on 2023/11/11.
//

#ifndef LEETCODE_231111_01_H
#define LEETCODE_231111_01_H
#include <vector>
using namespace std;
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ret = 0;
        for(int i=0;i<=limit;i++){
            for(int j=0;j<=limit;j++){
                int k=n-i-j;
                if(k>=0 && k<=limit)
                    ret++;
            }
        }
        return ret;
    }
};
#endif //LEETCODE_231111_01_H
