//
// Created by QinJM on 2023/9/25.
//

#ifndef LEETCODE_20_H
#define LEETCODE_20_H
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char a;
        for(char c : s){
            switch (c) {
                case '(':
                case '[':
                case '{':
                    st.push(c);
                    break;
                case ')':
                    if(st.empty() || '(' != st.top())
                        return false;
                    else
                        st.pop();
                    break;
                case ']':
                    if(st.empty() || '(' != st.top())
                        return false;
                    else
                        st.pop();
                    break;
                case '}':
                    if(st.empty() || '(' != st.top())
                        return false;
                    else
                        st.pop();
                    break;
            }
        }
        if(!st.empty())
            return false;
        return true;
    }
};
#endif //LEETCODE_20_H
