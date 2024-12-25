//
// Created by QinJM on 2023/12/31.
//

#ifndef LEETCODE_1154_H
#define LEETCODE_1154_H
#include <string>
#include <vector>
using namespace std;
class Solution {
private:
    int atoi(string s){
        int ret = 0;
        for(auto i : s){
            ret = 10 * ret + (i-'0');
        }
        return ret;
    }
public:
    int dayOfYear(string date) {
        vector<int> days_of_month = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int year = atoi(date.substr(0,4));
        int month = atoi(date.substr(5,2));
        int day = atoi(date.substr(8,2));
        int ans = days_of_month[month-1] + day;
        if((year%400==0) || (year%100!=0 && year%4==0)){
            if(month>2){
                ans = ans + 1;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_1154_H
