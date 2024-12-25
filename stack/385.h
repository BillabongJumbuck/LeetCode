//
// Created by QinJM on 2023/11/5.
//

#ifndef LEETCODE_385_H
#define LEETCODE_385_H
#include<vector>
#include<string>
using std::vector;
using std::string;
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
    public:
      // Constructor initializes an empty nested list.
     NestedInteger();

      // Constructor initializes a single integer.
      NestedInteger(int value);

     // Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     // Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

     // Set this NestedInteger to hold a single integer.
     void setInteger(int value);

     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
     void add(const NestedInteger &ni);

     // Return the nested list that this NestedInteger holds, if it holds a nested list
     // The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
};

class Solution {
private:
    NestedInteger& func(string& s,int &i){
        NestedInteger* res = new NestedInteger();
        for(;i<s.size();++i){
            if(s[i] == ',')
                continue;
            else if('0'<=s[i] && s[i]<='9'){
                int tmp = static_cast<int>(s[i]-'0');
                while('0'<=s[i+1] && s[i+1]<='9'){
                    i++;
                    tmp = 10*tmp + static_cast<int>(s[i]-'0');
                }
                res->add(NestedInteger(tmp));
            }
            else if(s[i] == '['){
                i++;
                res->add(func(s,i));
            }else if(s[i] == ']'){
                ++i;
                break;
            }
        }
        return *res;
    }
public:
    NestedInteger deserialize(string s) {
        int i = 0;
        return func(s, i);
    }
};
#endif //LEETCODE_385_H
