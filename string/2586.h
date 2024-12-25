//
// Created by QinJM on 2023/11/7.
//

#ifndef LEETCODE_2586_H
#define LEETCODE_2586_H
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0;
        while(left<=right){
            string tmp = words[left];
            if(isVowel(tmp[0]) && isVowel(tmp[tmp.size()-1]))
                count++;
            left++;
        }
        return count;
    }
};
#endif //LEETCODE_2586_H
