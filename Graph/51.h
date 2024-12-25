//
// Created by QinJM on 2023/12/20.
//

#ifndef LEETCODE_51_H
#define LEETCODE_51_H
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
class Solution {
private:
    bool is_valid(vector<int> &board, int index, int i){
        for(int j=0;j<index;j++){
            if(abs(index-j) == abs(board[j] - i) || index == j || board[j] == i){
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> board(n,-1);
        deque<vector<int>> open_list;
        open_list.push_back(board);
        int index = 0;
        while(index < n){
            int size = open_list.size();
            while(size-->0){
                board = open_list.front(); open_list.pop_front();
                for(int i=0;i<n;i++){
                    vector<int> tmp = board;
                    tmp[index] = i;
                    if(is_valid(tmp, index, i)){
                        open_list.push_back(tmp);
                    }
                }
            }
            index++;
        }
        vector<vector<string>> ans;
        for(auto& i : open_list){
            vector<string> tmp;
            for(int j : i){
                string s(n,'.');
                s[j] = 'Q';
                tmp.push_back(s);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
#endif //LEETCODE_51_H
