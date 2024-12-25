//
// Created by QinJM on 2023/12/20.
//

#ifndef LEETCODE_2828_H
#define LEETCODE_2828_H
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string tmp;
        for(auto i : words){
            tmp += i[0];
        }

        return tmp == s;
    }
};
#endif //LEETCODE_2828_H
