//
// Created by QinJM on 2023/11/8.
//

#ifndef LEETCODE_2609_H
#define LEETCODE_2609_H
#include <string>
using namespace std;
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int count0 = 0, count1 = 0;
        int ret= 0;
        int mintmp;
        for(int i=0;i<s.size();i++){
            if(i==0 && s[i]=='1'){
                while(s[i+1]=='i')
                    i++;
            }else if(s[i]=='0'){
                count0++;
            }else if(s[i]=='1'){
                count1++;
                if(s[i+1]=='0' || i==s.size()-1){
                    mintmp = count0>count1 ? count1 : count0;
                    ret = ret>mintmp ? ret : mintmp;
                    count1 = 0;
                    count0 = 0;
                }
            }
        }
        return 2*ret;
    }
};
#endif //LEETCODE_2609_H
