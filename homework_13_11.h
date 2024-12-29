//
// Created by QinJM on 24-12-29.
//

#ifndef LEETCODE_HOMEWORK_13_11_H
#define LEETCODE_HOMEWORK_13_11_H

#include <vector>

using std::vector;

class Solution {
private:
    bool is_valid_move(int x, int y, vector<vector<int>> &board) {
        // 检查移动是否有效（在棋盘内且未被访问）
        return (x >= 0 && y >= 0 && x < 8 && y < 8 && board[x][y] == -1);
    }

    bool solve_func(int x, int y, int move_i, vector<vector<int>> &board,
                    const vector<int> &next_x, const vector<int> &next_y) {
        if (move_i == 8 * 8) {
            // 检查最后一步是否能回到起始位置
            for (int i = 0; i < next_x.size(); ++i) {
                if (x + next_x[i] == 0 && y + next_y[i] == 0)
                    return true;
            }
            return false;
        }

        for (int i = 0; i < next_x.size(); ++i) {
            int next_x_pos = x + next_x[i];
            int next_y_pos = y + next_y[i];
            if (is_valid_move(next_x_pos, next_y_pos, board)) {
                board[next_x_pos][next_y_pos] = move_i;
                if (solve_func(next_x_pos, next_y_pos, move_i + 1, board, next_x, next_y))
                    return true;
                // 回溯
                board[next_x_pos][next_y_pos] = -1;
            }
        }
        return false;
    }
public:
    bool maZhouYou(int start_x, int start_y) {
        vector<vector<int>> board(8, vector<int>(8, -1));
        vector<int> next_x = {2, 1, -1, -2, -2, -1, 1, 2};
        vector<int> next_y = {1, 2, 2, 1, -1, -2, -2, -1};

        board[start_x][start_y] = 0;

        if (solve_func(start_x, start_y, 1, board, next_x, next_y)) {
            // 解决方案存在
            return true;
        } else {
            // 解决方案存在
            return false;
        }
    }
};

#endif //LEETCODE_HOMEWORK_13_11_H
