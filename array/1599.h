//
// Created by QinJM on 2024/1/1.
//

#ifndef LEETCODE_1599_H
#define LEETCODE_1599_H
#include <vector>
using namespace std;
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int curren_wait = 0;
        int profit = 0;
        int max_profit = 0;
        int min_epoch = 0;
        int epoch = 0;
        int i=0;
        do{
            if(i<customers.size())
                curren_wait += customers[i];
            if(curren_wait > 4){
                profit += 4 * boardingCost - runningCost;
                curren_wait -= 4;
            }else{
                profit += curren_wait * boardingCost - runningCost;
                curren_wait = 0;
            }
            i++;
            epoch++;
            if(profit > max_profit){
                max_profit = profit;
                min_epoch = epoch;
            }
        }while(curren_wait>0 || i<customers.size());
        return (max_profit>0 ? min_epoch : -1);
    }
};
#endif //LEETCODE_1599_H
