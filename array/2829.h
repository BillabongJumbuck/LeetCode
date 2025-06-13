//
// Created by QinJM on 25-3-26.
//

#ifndef LEETCODE_2829_H
#define LEETCODE_2829_H

#include <vector>
using namespace std;

class Solution {
public:
    int getSum(int a1, int an, int n) {
        return (a1 + an ) * n / 2;
    }
    int minimumSum(int n, int k) {
        vector<int> ret = vector<int>();
        for (int i=1;i<=k/2;i++) {
            if (ret.size() < n) {
                ret.push_back(i);
            }else{
                break;
            }
        }

        while (ret.size() < n) {
            ret.push_back(k);
            k++;
        }

        int res = 0;
        for (int i=0;i<ret.size();i++) {
            res += ret[i];
        }

        return res;
    }
};
#endif //LEETCODE_2829_H
