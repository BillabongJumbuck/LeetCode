//
// Created by QinJM on 2023/10/23.
//

#ifndef LEETCODE_2678_H
#define LEETCODE_2678_H
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(const string& s: details){
            if((s[11] > '6') || (s[11] == '6' && s[12] > '0'))
                count++;
        }
        return count;
    }
};
#endif //LEETCODE_2678_H
