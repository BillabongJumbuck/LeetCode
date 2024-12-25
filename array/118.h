//
// Created by QinJM on 2023/10/21.
//

#ifndef LEETCODE_118_H
#define LEETCODE_118_H
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for(int i=0;i<numRows;i++){
            res[i] = vector<int>(i+1, 1);
            for(int j=1;j<i;j++){
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res;
    }
};
#endif //LEETCODE_118_H
