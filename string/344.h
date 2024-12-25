//
// Created by QinJM on 2023/12/14.
//

#ifndef LEETCODE_344_H
#define LEETCODE_344_H
#include <vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }
};
#endif //LEETCODE_344_H
