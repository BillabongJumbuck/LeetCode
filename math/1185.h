//
// Created by QinJM on 2023/12/30.
//

#ifndef LEETCODE_1185_H
#define LEETCODE_1185_H
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> date = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> days_of_month = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int years = year - 1971;
        int leap_year = (years+2)/4;

        int days = years * 365  + leap_year + days_of_month[month-1] + day;
        if((year%400==0) || (year%100!=0 && year%4==0)){
            if(month > 2)
                days = days + 1;
        }
        return date[(days+4)%7];
    }
};
#endif //LEETCODE_1185_H
