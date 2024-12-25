//
// Created by QinJM on 2023/11/20.
//

#ifndef LEETCODE_89_H
#define LEETCODE_89_H
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        for(int i=0;i< pow(2,n);i++){
            vector<int> tmp(n, 0);
            int num = i;
            for(int j=n-1;j>=0;j--){
                tmp[j] = num%2;
                num = num/2;
                if(num == 0)
                    break;
            }
            int ans = tmp[0]*pow(2,n-1);
            for(int j=1;j<n;j++){
                ans += (tmp[j]^tmp[j-1])*pow(2,n-j-1);
            }
            ret.push_back(ans);
        }
        return ret;
    }
};

#endif //LEETCODE_89_H
