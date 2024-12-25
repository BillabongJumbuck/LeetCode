//
// Created by QinJM on 2023/12/10.
//

#ifndef LEETCODE_231210_02_H
#define LEETCODE_231210_02_H
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ret;
        for(int i=0;i<variables.size();i++){
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];
            long long x1 = static_cast<long long>(pow(a,b))%10;
            long long x2 = static_cast<long long>(pow(x1,c))%m;
            if(x2 == target)
                ret.push_back(i);
        }
        return ret;
    }
};
#endif //LEETCODE_231210_02_H
