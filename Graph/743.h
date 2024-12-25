//
// Created by QinJM on 2023/11/19.
//

#ifndef LEETCODE_743_H
#define LEETCODE_743_H

#include <vector>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph(n, vector<int>(n, 1e6));
        for(auto i : times){
            graph[i[0]-1][i[1]-1] = i[2];
        }
        for(int i=0;i<n;i++)
            graph[i][i] = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int l=0;l<n;l++){
                    if(graph[j][i]+graph[i][l]<graph[j][l]){
                        graph[j][l] = graph[j][i]+graph[i][l];
                    }
                }
            }
        }
        int ret = 0;
        for(int i=0;i<n;i++){
            if(graph[k-1][i] > ret)
                ret = graph[k-1][i];
        }
        return ret==1e6?-1:ret;
    }
};
#endif //LEETCODE_743_H
