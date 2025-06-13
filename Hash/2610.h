//
// Created by QinJM on 25-3-19.
//

#ifndef LEETCODE_2610_H
#define LEETCODE_2610_H
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<unordered_set<int>> set;
        for (auto num : nums) {
            bool flag = true;
            for (auto & i : set) {
                if (i.find(num) == i.end()) {
                    i.insert(num);
                    flag = false;
                    break;
                }
            }
            if (flag) {
                set.push_back(unordered_set<int>{num});
            }
        }
        vector<vector<int>> res;
        res.reserve(set.size());
        for (auto& i : set) {
            res.emplace_back(i.begin(), i.end());
        }
        return res;
    }
};
#endif //LEETCODE_2610_H
