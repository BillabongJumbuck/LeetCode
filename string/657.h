//
// Created by QinJM on 2023/11/18.
//

#ifndef LEETCODE_657_H
#define LEETCODE_657_H
#include <string>
using namespace std;
class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0, y=0;
        for(auto &c: moves){
            switch (c) {
                case 'D':
                    y-=1;
                    break;
                case 'U':
                    y+=1;
                    break;
                case 'L':
                    x-=1;
                    break;
                case 'R':
                    x+=1;
                    break;
            }
        }
        return ((x==0) && (y==0));
    }
};
#endif //LEETCODE_657_H
