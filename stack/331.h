//
// Created by QinJM on 2023/11/3.
//

#ifndef LEETCODE_331_H
#define LEETCODE_331_H
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.empty())
            return true;
        stack<int> num;
        for(int i=0;i<preorder.size();++i){
            if(preorder[i] == ',')
                continue;
            else if('0'<=preorder[i] && preorder[i]<='9'){
                int tmp = static_cast<int>(i-'0');
                while('0'<=preorder[i+1] && preorder[i+1]<='9'){
                    ++i;
                    tmp = tmp * 10 + static_cast<int>(i-'0');
                }
                num.push(tmp);
            }
            else if(preorder[i] == '#'){
                if(num.empty()){
                    if(i==preorder.size()-1)
                        return true;
                    else
                        return false;
                }
                else
                    num.pop();
            }
        }
        return false;
    }
};
#endif //LEETCODE_331_H
