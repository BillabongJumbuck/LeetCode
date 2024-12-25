//
// Created by QinJM on 2023/11/15.
//

#ifndef LEETCODE_210_H
#define LEETCODE_210_H
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }

        vector<int> Indgree(numCourses, 0);
        queue<int> q;
        for(int i=0;i<numCourses;++i){
            for(int j=0;j<numCourses;j++){
                if(graph[j][i] == 1)
                    Indgree[i]++;
            }
            if(Indgree[i]==0)
                q.push(i);
        }

        int cnt = 0;
        int tmp = 0;
        vector<int> ret;
        while(!q.empty()){
            tmp = q.front(); q.pop();
            cnt++;
            ret.push_back(tmp);
            Indgree[tmp] = -1;
            for(int i=0;i<numCourses;i++){
                if(graph[tmp][i] == 1){
                    Indgree[i]--;
                    if(Indgree[i] == 0)
                        q.push(i);
                }
            }
        }
        if(cnt != numCourses)
            ret.clear();
        return ret;
    }
};
#endif //LEETCODE_210_H
