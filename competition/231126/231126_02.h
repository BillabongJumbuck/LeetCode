//
// Created by QinJM on 2023/11/26.
//

#ifndef LEETCODE_231126_02_H
#define LEETCODE_231126_02_H
#include <string>
using namespace std;
class Solution {
private:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c== 'i' || c== 'o' || c=='u');
    }
    bool isBeatufulString(string &s, int i, int j,int k){
        if(i>j)
            return false;
        int vowels = 0;
        int consonants = 0;
        for(;i<=j;i++){
            if(isVowel(s[i])){
                vowels++;
            }else{
                consonants++;
            }
        }

        if ((vowels == consonants) && ((vowels * consonants) % k == 0))
            return true;

        return false;
    }
public:
    int beautifulSubstrings(string s, int k) {
       int ret = 0;
       int begin = 0;
       int end = s.size();
       while(begin<=end){
           for(int i=begin;i<=end;i++){
               if(isBeatufulString(s , begin, i , k))
                   ret++;
               if(isBeatufulString(s, i, end-1, k))
                   ret++;
           }
           begin++;
           end--;
       }
        return ret;
    }
};
#endif //LEETCODE_231126_02_H
