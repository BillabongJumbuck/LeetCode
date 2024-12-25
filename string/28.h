//
// Created by QinJM on 2024/1/2.
//

#ifndef LEETCODE_28_H
#define LEETCODE_28_H
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    vector<int> next;
    vector<int> nextVal;
    void gen_next(const string& needle){
        next = vector<int>(needle.size(), -1);
        for(int i=0;i<next.size();i++){
            if(i==0)
                next[i] = -1;
            else if(i==1)
                next[i] = 0;
            else{
                string sub = needle.substr(0,i);
                for(int j=i-1;j>0;j--){
                    string tmp = needle.substr(0, j);
                    bool isMatch = true;
                    for(int k=0;k<j;k++){
                        if(sub[i-k-1] != tmp[j-k-1]){
                            isMatch = false;
                            break;
                        }
                    }
                    if(isMatch){
                        next[i] = j;
                        break;
                    }
                    else
                        next[i] = 0;
                }
            }
        }
    }
    void gen_nextVal(const vector<int> &next, const string& needle){
        nextVal = next;
        for(int i=0;i<nextVal.size();i++){
            if(i==0)
                continue;
            else if(needle[i] == needle[next[i]])
                nextVal[i] = nextVal[next[i]];
        }
    }
public:
    int strStr(string haystack, string needle) {
        gen_next(needle);
        gen_nextVal(next, needle);
        int i=0, j=0;
        // 注意needle.size()为size_t类型,j=-1时, -1>size_t, 会发生意想不到的错误!!!
        while(i<static_cast<int>(haystack.size()) && j<static_cast<int>(needle.size())){
            if(j==-1 || haystack[i]==needle[j]){
                i++;
                j++;
            }else{
                j = nextVal[j];
            }
        }
        if( j== needle.size())
            return (i - j);
        else
            return -1;
    }
};
#endif //LEETCODE_28_H
