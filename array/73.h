//
// Created by QinJM on 2023/12/18.
//

#ifndef LEETCODE_73_H
#define LEETCODE_73_H
#include <vector>
using std::vector;
class Solution {
private:
    void set_zero(vector<vector<int>> &v,int x, int y, int row, int col){
        for(int i=0;i<col;i++)
            v[x][i] = 0;
        for(int j=0;j<row;j++)
            v[j][y] = 0;
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> tmp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0)
                    tmp.push_back(vector<int>{i,j});
            }
        }
        for(auto i : tmp){
            set_zero(matrix, i[0], i[1], matrix.size(),matrix[0].size());
        }
    }
};
#endif //LEETCODE_73_H
