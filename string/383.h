//
// Created by QinJM on 2024/1/7.
//

#ifndef LEETCODE_383_H
#define LEETCODE_383_H
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size())
            return false;
        map<char, int> m;
        for(auto c : magazine){
            m[c] ++;
        }
        for(auto c : ransomNote){
            if(m[c] == 0)
                return false;
            else
                m[c] --;
        }
        return true;
    }
};
#endif //LEETCODE_383_H
