//
// Created by QinJM on 2023/11/18.
//

#ifndef LEETCODE_547_H
#define LEETCODE_547_H
#include <vector>
using namespace std;
class Solution {
private:
    vector<int> set;
    int Find(int x){
        for(;set[x]>=0;x=set[x]);
        return x;
    }
    void Union(int root1, int root2){
        if(set[root2]<set[root1]){
            set[root2] += set[root1];
            set[root1] = root2;
        }else{
            set[root1] += set[root2];
            set[root2] = root1;
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        set = vector(isConnected.size(), -1);
        for(int i=0;i<isConnected.size();i++){
            for(int j=i;j<isConnected.size();j++){
                if(isConnected[i][j] == 1){
                    if(Find(i) != Find(j))
                        Union(Find(i) , Find(j));
                }
            }
        }
        int ret = 0;
        for(int i : set)
            if(i<0)
                ret++;
        return ret;
    }
};
#endif //LEETCODE_547_H
