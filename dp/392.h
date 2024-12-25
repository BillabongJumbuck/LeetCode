//
// Created by QinJM on 24-12-24.
//

#ifndef LEETCODE_392_H
#define LEETCODE_392_H

#include <string>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0, j=0;
        while(j<t.size()){
            if(s[i] == t[j]){
                i++;
                if(i == s.size())
                    return true;
            }
            j++;
        }
        return i == s.size();
    }
};
#endif //LEETCODE_392_H
