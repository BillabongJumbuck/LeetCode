//
// Created by QinJM on 24-12-27.
//

#ifndef LEETCODE_221_H
#define LEETCODE_221_H
#include <vector>
using namespace std;
class Solution {
private:
    int gen_square(int a, int b, int c){
        int min_num = min(min(a, b), c);
        return min_num + 1;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> dp(n);
        int max_square = 0;
        for(int i=0;i<n;i++){
            dp[i] = (matrix[0][i] == '1');
            max_square = max(max_square, dp[i]);
        }
        int pre = 0;
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    pre = (matrix[i][j] == '1');
                }else if(matrix[i][j] == '1'){
                    int temp = pre;
                    pre = gen_square(dp[j], dp[j-1], pre);
                    dp[j-1] = temp;
                }else{
                    dp[j-1] = pre;
                    pre = 0;
                }
                max_square = max(max_square, pre);
            }
            dp[n-1] = pre;
        }
        return max_square * max_square;
    }
};
#endif //LEETCODE_221_H
