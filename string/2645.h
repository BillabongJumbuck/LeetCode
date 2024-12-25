//
// Created by QinJM on 2024/1/11.
//

#ifndef LEETCODE_2645_H
#define LEETCODE_2645_H
#include <string>
using std::string;
class Solution {
public:
    int addMinimum(string word) {
        int ans = 0;
        int a_flag = 0;
        int b_flag = 0;
        for(int i=0;i<word.length();i++){
            if(word[i] == 'a'){
                if(a_flag || b_flag){
                    ans += 3 - a_flag - b_flag;
                    a_flag = 1;
                    b_flag = 0;
                }else{
                    a_flag = 1;
                }
            }else if(word[i] == 'b'){
                if(b_flag){
                    ans += 3 - a_flag - b_flag;
                    a_flag = 0;
                    b_flag = 1;
                }else{
                    b_flag = 1;
                }
            }else if(word[i] == 'c'){
                ans += 2 - a_flag - b_flag;
                a_flag = 0;
                b_flag = 0;
            }
        }
        if(word.back() == 'c')
            return ans;
        else
            return ans + 3 - a_flag - b_flag;
    }
};
#endif //LEETCODE_2645_H
