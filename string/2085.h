//
// Created by QinJM on 2024/1/12.
//

#ifndef LEETCODE_2085_H
#define LEETCODE_2085_H
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        int ans = 0;
        map<string, int> m;
        for(const auto& c : words1){
            m[c]++;
        }
        for(const auto& c : words2){
            if(m[c] == 1){
                m[c] = -1;
                ans++;
            }else if(m[c] == -1){
                m[c] = 0;
                ans --;
            }

        }
        return ans;
    }
};
#endif //LEETCODE_2085_H
