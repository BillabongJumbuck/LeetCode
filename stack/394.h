//
// Created by QinJM on 2023/11/6.
//

#ifndef LEETCODE_394_H
#define LEETCODE_394_H
#include <string>
using std::string;
class Solution {
private:
    string& func(string &s, int& i){
        string ret;
        int count = 0;
        for(;i<s.size();++i){
            if('0'<=s[i] && s[i]<='9'){
                int tmp = static_cast<int>(s[i] - '0');
                while('0'<=s[i+1] && s[i]<='9'){
                    tmp = 10*tmp + static_cast<int>(s[i] - '0');
                }
                count = tmp;
            }
            else if('a'<=s[i] && s[i]<='z'){
                ret += s[i];
            }else if(s[i] == '['){
                string tmp;
                i++;
                tmp = func(s, i);
                while(count>0){
                    ret+=tmp;
                    --count;
                }
            }
            else if(s[i] == ']'){
                ++i;
                break;
            }
        }
        return ret;
    }
public:
    string decodeString(string s) {
        string ret;
        int i = 0;
        ret = func(s, i);
        return ret;
    }
};
#endif //LEETCODE_394_H
