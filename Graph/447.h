//
// Created by QinJM on 2024/1/8.
//

#ifndef LEETCODE_447_H
#define LEETCODE_447_H
#include <vector>
#include <map>
using namespace std;
class Solution {
private:
    int get_distance(vector<int> v1, vector<int> v2){
        return (v1[0]-v2[0])*(v1[0]-v2[0]) + (v1[1]-v2[1])*(v1[1]-v2[1]);
    }
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ret = 0;
        for(int i=0;i<points.size();i++){
            map<int, int> tmp;
            for(int j=0;j<points.size();j++){
                if(i != j){
                    int dist = get_distance(points[i], points[j]);
                    tmp[dist]++;
                }
            }
            for(const auto& item : tmp){
                ret += item.second * ( item.second-1);
            }
        }
        return ret;
    }
};
#endif //LEETCODE_447_H
