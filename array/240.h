//
// Created by QinJM on 2024/1/11.
//

#ifndef LEETCODE_240_H
#define LEETCODE_240_H
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0;
        int j=0;
        while(matrix[i][j] != target){
            if(matrix[i][j] < target && i != m-1){
                while(matrix[i][j] < target && i != m-1){
                    i = (i+m) / 2;
                }
            }else{
                while(matrix[i][j] > target && i != 0){
                    i = (i+0) / 2;
                }
            }

            if(matrix[i][j] == target)
                return true;

            if(matrix[i][j] < target && j != n-1){
                while(matrix[i][j] < target && j != n-1){
                    j = (j+m) / 2;
                }
            }else{
                while(matrix[i][j] > target && j != 0){
                    j = (j+0) / 2;
                }
            }
        }
        return true;
    }
};
#endif //LEETCODE_240_H
