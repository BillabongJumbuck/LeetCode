//
// Created by QinJM on 2023/11/25.
//

#ifndef LEETCODE_231125_01_H
#define LEETCODE_231125_01_H
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ret;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(words[i][j] == x){
                    ret.push_back(i);
                    break;
                }
            }
        }
        return ret;
    }
};
#endif //LEETCODE_231125_01_H
