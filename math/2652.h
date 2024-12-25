//
// Created by QinJM on 2023/10/17.
//

#ifndef LEETCODE_2652_H
#define LEETCODE_2652_H
class Solution {
public:
    int sumOfMultiples(int n) {
        bool *arry = new bool[n+1];
        for(int i=0;i<=n;++i)
            arry[i] = false;
        for(int i=1;3*i<=n;++i){
            if(3*i<=n)
                arry[3*i] = true;
            if(5*i<=n)
                arry[5*i] = true;
            if(7*i<=n)
                arry[7*i] = true;
        }
        int num = 0;
        for(int i=3;i<=n;++i){
            if(arry[i])
                num+=i;
        }
        delete[] arry;
        return num;
    }
};
#endif //LEETCODE_2652_H
