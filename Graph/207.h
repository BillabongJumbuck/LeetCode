//
// Created by QinJM on 2023/11/15.
//

#ifndef LEETCODE_207_H
#define LEETCODE_207_H
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]][prerequisites[i][1]] = 1;
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
        while(!q.empty()){
            tmp = q.front(); q.pop();
            cnt++;
            Indgree[tmp] = -1;
            for(int i=0;i<numCourses;i++){
                if(graph[tmp][i] == 1){
                    Indgree[i]--;
                    if(Indgree[i] == 0)
                        q.push(i);
                }
            }
        }
        return cnt == numCourses;
    }
};
#endif //LEETCODE_207_H