//
// Created by QinJM on 2023/11/11.
//

#ifndef LEETCODE_2311111_04_H
#define LEETCODE_2311111_04_H
#include <vector>
#include <cmath>
using std::vector;
class Solution {
    int findMin(vector<vector<int>>& values){
        int min=INT_MAX;
        int index=0;
        for(int i=0;i<values.size();++i){
            if(!values[i].empty() && values[i][values[i].size()-1]<min){
                min = values[i][values[i].size()-1];
                index = i;
            }
        }
        values[index].pop_back();
        return min;
    }
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long ret=0;
        for(int i=1;;i++){
            int k = findMin(values);
            if(k==INT_MAX)
                break;
            ret += 1L*k*i;
        }
        return ret;
    }
};
#endif //LEETCODE_2311111_04_H
