//
// Created by QinJM on 24-12-30.
//

#ifndef LEETCODE_77_H
#define LEETCODE_77_H
#include <vector>
using namespace std;
class Solution {
private:
    void backtrace(vector<vector<int>>& res, vector<int>& current, int back_num, int n, int k){
        if(current.size() == k){
            res.push_back(current);
            return;
        }
        for(int i=back_num+1;i<=n;i++){
            current.push_back(i);
            backtrace(res, current, i, n , k);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> current;
        backtrace(res, current, 0, n, k);
        return res;
    }
};
#endif //LEETCODE_77_H
