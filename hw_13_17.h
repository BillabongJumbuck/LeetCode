//
// Created by QinJM on 24-12-29.
//

#ifndef LEETCODE_HW_13_17_H
#define LEETCODE_HW_13_17_H

#include <vector>

using namespace std;

class Solution {
private:
    // 回溯算法寻找最优解
    void backtrack(int n, const vector<vector<int>> &cost, vector<bool> &assigned,
                   vector<int> &assignment, int &min_cost, int current_cost, int worker) {
        // 如果所有工人已经被指派，则更新最小成本
        if (worker == n) {
            min_cost = min(min_cost, current_cost);
            return;
        }

        // 尝试将当前工人指派给每个未被指派的工作
        for (int job = 0; job < n; ++job) {
            if (!assigned[job]) { // 工作还未被指派
                if (current_cost + cost[worker][job] >= min_cost) continue; // 剪枝

                // 指派工作并递归尝试下一个工人
                assigned[job] = true;
                assignment[worker] = job;
                backtrack(n, cost, assigned, assignment, min_cost, current_cost + cost[worker][job], worker + 1);

                // 回溯：撤销指派
                assigned[job] = false;
            }
        }
    }

public:
    vector<int> solve_assignment_problem(const vector<vector<int>> &cost) {
        int n = cost.size();
        vector<bool> assigned(n, false); // 记录哪些工作已被指派
        vector<int> assignment(n, -1);   // 每个工人的指派情况
        int min_cost = 1e9;                   // 初始化最小成本为一个很大的数

        // 开始回溯搜索
        backtrack(n, cost, assigned, assignment, min_cost, 0, 0);

        // 返回最小成本的指派方案
        return assignment;
    }
};

#endif //LEETCODE_HW_13_17_H
