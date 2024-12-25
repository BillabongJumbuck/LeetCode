//
// Created by QinJM on 2023/10/21.
//

#ifndef LEETCODE_2316_H
#define LEETCODE_2316_H
#include <vector>
using namespace std;
class Solution {
    vector<int> S;
    int Find(int x){
        for(; S[x]>=0; x = S[x]);
        return x;
    }
    void Union(int Root1, int Root2){
        if(Root1 == Root2)
            return;
        if(S[Root2]<S[Root1]){
            S[Root2] += S[Root1];
            S[Root1] = Root2;
        }else{
            S[Root1] += S[Root2];
            S[Root2] = Root1;
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        S = vector<int>(n, -1);
        for(auto i: edges){
            Union(Find(i[0]), Find(i[1]));
        }
        long long sum = 0;
        for(int i = 0; i<n; i++){
            sum += n + S[Find(i)];
        }
        return sum/2;
    }
};
#endif //LEETCODE_2316_H
