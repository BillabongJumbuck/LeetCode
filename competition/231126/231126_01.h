//
// Created by QinJM on 2023/11/26.
//

#ifndef LEETCODE_231126_01_H
#define LEETCODE_231126_01_H
#include <vector>
using namespace std;
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] != mat[i][(j+k)%n])
                    return false;
            }
        }
        return true;
    }
};
#endif //LEETCODE_231126_01_H
