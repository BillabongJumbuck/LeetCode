//
// Created by QinJM on 2024/1/10.
//

#ifndef LEETCODE_2696_H
#define LEETCODE_2696_H
#include <string>
#include <vector>
using namespace std;
// 实质：有效括号的匹配。
// 解法：维护一个栈。
class Solution {
public:
    int minLength(string s) {
        vector<char> stk;
        for(auto c : s){
            stk.push_back(c);
            int size = stk.size();
            if(size >=2 ){
                if(stk[size-1] == 'B' && stk[size-2] == 'A'){
                    stk.pop_back();
                    stk.pop_back();
                }
                if(stk[size-1] == 'D' && stk[size-2] == 'C'){
                    stk.pop_back();
                    stk.pop_back();
                }
            }
        }
        return stk.size();
    }
};
//class Solution {
//public:
//    int minLength(string s) {
//        auto i = s.begin();
//        while(i!=s.end()){
//            if(*i == 'A'){
//                if(i+1 !=s.end() && *(i+1)=='B'){
//                    i = s.erase(i, i+2);
//                    if(i != s.begin()){
//                        i--;
//                    }
//                    continue;
//                }
//            }else if(*i == 'C'){
//                if(i+1 !=s.end() && *(i+1)=='D'){
//                    i = s.erase(i, i+2);
//                    if(i != s.begin()){
//                        i--;
//                    }
//                    continue;
//                }
//            }
//            i++;
//        }
//        return s.size();
//    }
//};
#endif //LEETCODE_2696_H
