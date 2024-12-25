//
// Created by QinJM on 2023/12/22.
//

#ifndef LEETCODE_59_H
#define LEETCODE_59_H
#include <vector>
using namespace std;
void Fill(vector<vector<int>>& v, int& x, int& y, int n,int& count) {
    for (int i = 0; i < n; i++) {
        v[x][y + i] = count;
        count++;
    }
    y = y + (n - 1);
    for (int i = 1; i < n; i++) {
        v[x + i][y] = count;
        count++;
    }
    x = x + (n - 1);
    for (int i = 1; i < n; i++) {
        v[x][y - i] = count;
        count++;
    }
    y = y - (n - 1);
    for (int i = 1; i < n - 1; i++) {
        v[x - i][y] = count;
        count++;
    }
    x = x - (n - 2);
}
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> nums ;
        for (int i = 0; i < n; ++i)
            nums.push_back(vector<int>(n, 0));

        int x = 0 , y= 0, count = 1;
        while(n>0){
            Fill(nums, x, y, n, count);
            y+=1;
            n-=2;
        }
        return nums;
    }
};
#endif //LEETCODE_59_H
