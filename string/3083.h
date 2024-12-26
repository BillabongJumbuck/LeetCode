//
// Created by QinJM on 24-12-26.
//

#ifndef LEETCODE_3083_H
#define LEETCODE_3083_H
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isSubstringPresent(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        for(int i=0;i<s.size()-1;i++){
            string sub = s.substr(i, 2);
            if(temp.find(sub) != string::npos){
                return true;
            }
        }
        return false;
    }
};
#endif //LEETCODE_3083_H
