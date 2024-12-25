//
// Created by QinJM on 2023/11/25.
//

#ifndef LEETCODE_119_H
#define LEETCODE_119_H
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res(rowIndex+1);
        for(int i=0;i<=rowIndex;i++){
            res[i] = vector<int>(i+1, 1);
            for(int j=1;j<i;j++){
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
        return res.back();
    }
};
#endif //LEETCODE_119_H
