//
// Created by QinJM on 2023/12/6.
//

#ifndef LEETCODE_797_H
#define LEETCODE_797_H
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> path;
        if(graph.empty())
            return path;
        int n = graph.size()-1;
        queue<int> q_node;
        q_node.push(0);
        queue<vector<int>> q_path;
        q_path.push(vector<int>{0});
        while(!q_node.empty()){
            int size = q_node.size();
            while(size>0){
                size--;
                int node = q_node.front(); q_node.pop();
                vector<int> p = q_path.front(); q_path.pop();
                if(!graph[node].empty()){
                    for(auto i : graph[node]){
                        vector<int> tmp = p;
                        tmp.push_back(i);
                        if(i == n){
                            path.push_back(tmp);
                        }else{
                            q_node.push(i);
                            q_path.push(tmp);
                        }
                    }
                }
            }
        }
        return path;
    }
};
#endif //LEETCODE_797_H
