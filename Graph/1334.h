//
// Created by QinJM on 2023/11/14.
//

#ifndef LEETCODE_1334_H
#define LEETCODE_1334_H
#include <vector>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> graph(n, vector<int>(n, 1e5));
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]][edges[i][1]] = edges[i][2];
            graph[edges[i][1]][edges[i][0]] = edges[i][2];
            if(i<n)
                graph[i][i] = 0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(graph[j][i] + graph[i][k] < graph[j][k]){
                        graph[j][k] = graph[j][i] + graph[i][k];
                    }
                }
            }
        }
        int ret = n;
        int mincount = 1e5;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(graph[i][j] <= distanceThreshold)
                    count++;
            }
            if(count<=mincount){
                ret = i;
                mincount = count;
            }
        }
        return ret;
    }
};
#endif //LEETCODE_1334_H
