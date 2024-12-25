//
// Created by QinJM on 2023/12/1.
//

#ifndef LEETCODE_2661_H
#define LEETCODE_2661_H
#include <vector>
#include <map>
using namespace std;
struct position{
    int row;
    int col;
    position() = default;
    position(int r, int c){
        row = r;
        col = c;
    }
};
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int, position> map1;
        vector<int> row_num(mat.size(), 0);
        vector<int> col_num(mat[0].size(), 0);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                map1.insert(pair<int, position>(mat[i][j], position(i,j)));
            }
        }
        for(int i=0;i<arr.size();i++){
            row_num[map1[arr[i]].row]++;
            col_num[map1[arr[i]].col]++;
            if(row_num[map1[arr[i]].row]== mat[0].size() || col_num[map1[arr[i]].col]==mat.size())
                return i;
        }
        return -1;
    }
};
#endif //LEETCODE_2661_H
