//
// Created by QinJM on 2023/11/5.
//
#ifndef LEETCODE_709_H
#define LEETCODE_709_H
#include <string>
#include <cstring>
using namespace std;
class Solution {
public:
    string toLowerCase(string s) {
        for(char& c : s){
            c = tolower(c);
        }
        return s;
    }
};
#endif //LEETCODE_709_H
