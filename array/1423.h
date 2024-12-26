//
// Created by QinJM on 2023/12/3.
//

#ifndef LEETCODE_1423_H
#define LEETCODE_1423_H
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int window_sum = 0;
        int window_size = cardPoints.size() - k;
        int i=0;
        for(;i<window_size;i++){
            window_sum += cardPoints[i];
        }
        int min_sum = window_sum;
        int all_sum = window_sum;
        for(;i<cardPoints.size();i++){
            all_sum += cardPoints[i];
            window_sum = window_sum - cardPoints[i-window_size] + cardPoints[i];
            if(window_sum < min_sum)
                min_sum = window_sum;
        }
        return all_sum - min_sum;
    }
};
#endif //LEETCODE_1423_H
