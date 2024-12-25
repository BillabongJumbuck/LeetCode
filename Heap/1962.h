//
// Created by QinJM on 2023/12/23.
//

#ifndef LEETCODE_1962_H
#define LEETCODE_1962_H
#include <vector>
#include <queue>
#include <numeric>
using namespace std;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q(piles.begin(), piles.end());
        while(k-->0){
            q.push((q.top()+1)/2);
            q.pop();
        }
        int ans = 0;
        while(!q.empty()){
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};
#endif //LEETCODE_1962_H
