//
// Created by QinJM on 2023/11/12.
//

#ifndef LEETCODE_231112_03_H
#define LEETCODE_231112_03_H
#include <vector>
#include <queue>
using namespace std;
class Solution {
private:
    bool isValid(vector<int> num){
        int flag = num[num.size()-1];
        for(int i=0;i<num.size()-1;++i) {
            if (num[i] > flag)
                return false;
        }
        return true;
    }
    void Swap(int *a, int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
    int findLast1(vector<int>& flag){
        int position = 0;
        for(int i=0;i<flag.size();++i){
            if(flag[i] == 1)
                position = i;
        }
        return position;
    }
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> flag(n, 0);
        queue<pair<vector<int>, vector<int>>> qnum;
        queue<vector<int>> qflag;
        int ret = 0;
        qnum.push(pair<vector<int>,vector<int>>(nums1, nums2));
        qflag.push(flag);
        while(!qnum.empty()){
            int size = qnum.size();
            while(size>0){
                pair<vector<int>, vector<int>> tmp = qnum.front(); qnum.pop();
                vector<int> tmpflag = qflag.front(); qflag.pop();
                if(isValid(tmp.first) && isValid(tmp.second))
                    return ret;
                else{
                    for(int i=findLast1(tmpflag);i<n;i++){
                        vector<int> a(tmpflag.begin(), tmpflag.end());
                        pair<vector<int>, vector<int>> b(tmp.first, tmp.second);
                        if(a[i] == 0){
                            a[i] = 1;
                            Swap(&b.second[i], &b.first[i]);
                            qnum.push(b);
                            qflag.push(a);
                        }
                    }
                }
                --size;
            }
            ++ret;
        }
        return -1;
    }
};
#endif //LEETCODE_231112_03_H
