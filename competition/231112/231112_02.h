//
// Created by QinJM on 2023/11/12.
//

#ifndef LEETCODE_231112_02_H
#define LEETCODE_231112_02_H
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string, vector<int>> m;
        for(auto & access_time : access_times){
            if(m.find(access_time[0]) == m.end()){
                m.insert(pair<string, vector<int>>(access_time[0], vector<int>{stoi(access_time[1])}));
            }
            else{
                m[access_time[0]].push_back(stoi(access_time[1]));
            }
        }
        vector<string> ret;
        for(auto& elem : m){
            if(elem.second.size()<3)
                continue;
            else{
                for(int i=0;i<elem.second.size()-2;++i){
                    int a = elem.second[i]-100;
                    int b = elem.second[i]+100;
                    for(int j=i+1;j<elem.second.size()-1;++j){
                        if(a<elem.second[j] && elem.second[j]<b){
                            int c = max(a, elem.second[j]-100);
                            int d = min(b, elem.second[j]+100);
                            for(int k=j+1;k<elem.second.size();++k){
                                if(c<elem.second[k] && elem.second[k]<d){
                                    ret.push_back(elem.first);
                                    k = elem.second.size();
                                    j = elem.second.size()-1;
                                    i = elem.second.size()-2;
                                }
                            }
                        }
                    }
                }
            }
        }
        return ret;
    }
};
#endif //LEETCODE_231112_02_H
