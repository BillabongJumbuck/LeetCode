//
// Created by QinJM on 2023/10/30.
//

#ifndef LEETCODE_224_H
#define LEETCODE_224_H
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int calculate(string s){

    }
//    int calculate(string s) {
//        string a;
//        stack<char> op;
//        stack<int> num;
//        for(int i=0;i<s.size();i++){
//            if(s[i] == ' ')
//                continue;
//            else if('0'<= s[i] && s[i]<='9'){
//                int tmp = s[i]-'0';
//                if(i+1<s.size()){
//                    while('0'<= s[i+1] && s[i+1]<='9'){
//                        ++i;
//                        tmp = tmp * 10 + static_cast<int>(s[i] - '0');
//                    }
//                }
//                a += to_string(tmp) + ' ';
//            }
//            else if(s[i] == '('){
//                op.push(s[i]);
//            }
//            else if(s[i] == ')'){
//                while(op.top() != '('){
//                    a += op.top();
//                    op.pop();
//                }
//                op.pop();
//            }
//            else if( (s[i]=='+') || (s[i]=='-')){
//                if(op.empty() || op.top()=='(')
//                    op.push(s[i]);
//                else{
//                    while(!op.empty() && op.top()!= '('){
//                        a += op.top();
//                        op.pop();
//                    }
//                    op.push(s[i]);
//                }
//            }else if( (s[i]=='*') || (s[i]=='/')){
//                if(op.empty())
//                    op.push(s[i]);
//                else if((op.top()=='+') || (op.top()=='-') || (op.top()=='('))
//                    op.push(s[i]);
//                else{
//                    while(!op.empty() && (op.top()=='*' || op.top()=='/')){
//                        a += op.top();
//                        op.pop();
//                        if(op.top()=='(')
//                            break;
//                    }
//                    op.push(s[i]);
//                }
//            }
//        }
//        while(!op.empty()){
//            a += op.top();
//            op.pop();
//        }
//        for(int i=0;i<a.size();i++){
//            if(a[i] == ' ')
//                continue;
//            else if(a[i]>='0' && a[i]<='9'){
//                int tmp = a[i]-'0';
//                if(i+1<a.size()){
//                    while('0'<= a[i+1] && a[i+1]<='9'){
//                        ++i;
//                        tmp = 10 *tmp + static_cast<int>(a[i] - '0');
//                    }
//                }
//                num.push(tmp);
//            }
//            else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/'){
//                int x = num.top(); num.pop();
//                int y = num.top(); num.pop();
//                switch (a[i]) {
//                    case '+':
//                        num.push(x+y);
//                        break;
//                    case '-':
//                        num.push(y-x);
//                        break;
//                    case '*':
//                        num.push(x*y);
//                        break;
//                    case '/':
//                        num.push(y/x);
//                        break;
//                }
//            }
//        }
//        int ans = num.top();
//        num.pop();
//        return ans;
//    }
};
#endif //LEETCODE_224_H
