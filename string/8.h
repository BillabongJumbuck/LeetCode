//
// Created by QinJM on 2023/12/24.
//

#ifndef LEETCODE_8_H
#define LEETCODE_8_H
#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool is_negative = false;
        bool sign = false;
        long long max = 2147483647;
        for(auto c : s){
            if(c==' ' && !sign){
                continue;
            }else if(c=='+'&& !sign){
                sign = true;
            }
            else if(c == '-' && !sign){
                sign = true;
                is_negative = true;
            }
            else if('0'<=c && c<='9'){
                sign = true;
                ans = 10 * ans + static_cast<int>(c-'0');
                if(ans > max){
                    if(is_negative)
                        ans = max+1;
                    else
                        ans = max;
                    break;
                }
            }else{
                break;
            }
        }
        if(is_negative)
            ans = 0-ans;
        return ans;
    }
};
#endif //LEETCODE_8_H
