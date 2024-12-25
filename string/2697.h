//
// Created by QinJM on 2023/12/13.
//

#ifndef LEETCODE_2697_H
#define LEETCODE_2697_H
#include <string>
#include <iterator>
using namespace std;
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        auto a = s.begin();
        auto b = s.end() - 1;
        while(a<b){
            if(*a != *b){
                if(*a < *b)
                    *b = *a;
                else
                    *a = *b;
            }
            a++;
            b--;
        }
        return s;
    }
};
#endif //LEETCODE_2697_H
