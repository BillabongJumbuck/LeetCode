//
// Created by QinJM on 2023/10/13.
//

#ifndef LEETCODE_150_H
#define LEETCODE_150_H
#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int a = 0, b = 0, value = 0;
        stack<int> s;
        for(string& i: tokens){
            if((i[0] >= 48 && i[0] <=57) || (i[0] == '-' && i.size()>1)){
                s.push(convert(i));
            }else{
                a=s.top();s.pop();
                b=s.top();s.pop();
                switch (i[0]) {
                    case '+':
                        s.push(b+a);
                        break;
                    case '-':
                        s.push(b-a);
                        break;
                    case '*':
                        s.push(b*a);
                        break;
                    case '/':
                        s.push(b/a);
                        break;
                }
            }
        }
        return s.top();
    }
    int convert(string s){
        int num = 0;
        int flag = 1;
        for(auto c: s){
            if(c == '-'){
                flag = -1;
            }else{
                num = num*10 + static_cast<int>(c-48);
            }
        }
        return num * flag;
    }
};
#endif //LEETCODE_150_H
