//
// Created by QinJM on 2023/10/1.
//

#ifndef LEETCODE_121_H
#define LEETCODE_121_H
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    // 单调栈
//    int maxProfit(vector<int>& prices) {
//        stack<int> s;
//        vector<int> max(prices.size(), -1);
//        for(int i = prices.size()-1; i>=0; i--){
//            if(s.empty()){
//                s.push(prices[i]);
//                max[i] = prices[i];
//            }else if(prices[i] > s.top()){
//                s.push(prices[i]);
//                max[i] = prices[i];
//            }else{
//                max[i] = s.top();
//            }
//        }
//        int res = 0;
//        for(int i=0;i<prices.size();i++){
//            int profit = max[i] - prices[i];
//            if(profit > res)
//                res = profit;
//        }
//        return res;
//    }
    // 动态规划？
    int maxProfit(vector<int>& prices) {
        int minPrice = 1e9;
        int maxProfit = 0;
        for(auto price : prices){
            if(price < minPrice){
                minPrice = price;
            }else if(price - minPrice > maxProfit){
                maxProfit = price - minPrice;
            }
        }
        return maxProfit;
    }
};
#endif //LEETCODE_121_H
