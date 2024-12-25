//
// Created by QinJM on 2023/12/7.
//

#ifndef LEETCODE_14_H
#define LEETCODE_14_H
# include <string>
# include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        int size = strs[0].size();
        for(;i<size;i++){
            char c = strs[0][i];
            for(auto s : strs){
                if(s[i] != c || i == s.size())
                    break;
            }
        }
        return strs[0].substr(0,i);
    }
};
#endif //LEETCODE_14_H
