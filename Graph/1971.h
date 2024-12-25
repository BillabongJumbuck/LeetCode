//
// Created by QinJM on 2023/10/27.
//

#ifndef LEETCODE_1971_H
#define LEETCODE_1971_H
#include <vector>
using namespace std;
class Solution {
private:
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        S = vector<int>(n, -1);
        for(auto i: edges){
            Union(Find(i[0]), Find(i[1]));
        }
        if(Find(source) == Find(destination))
            return true;
        return false;
    }
};
#endif //LEETCODE_1971_H
