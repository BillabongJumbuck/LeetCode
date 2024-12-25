//
// Created by QinJM on 2024/1/9.
//

#ifndef LEETCODE_56_H
#define LEETCODE_56_H
#include <vector>
using namespace std;
class Solution {
private:
    bool is_less(vector<int>& v1, vector<int>& v2){
        if(v1[0] < v2[0])
            return true;
        else if(v1[0]==v2[0] && v1[1] < v2[1])
            return true;
        else
            return false;
    }
    void buildHeap(vector<vector<int>>& v, int p, int n){
        int parent, child;
        vector<int> x = v[p];
        for(parent=p; 2*parent+1<=n; parent=child){
            child = 2*parent+1;
            if(child+1<=n && is_less(v[child+1], v[child]))
                child++;
            if(is_less(x, v[child]))
                break;
            else
                v[parent] = v[child];
        }
        v[parent] = x;
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.empty())
            return ans;
        for(int i=intervals.size()/2;i>=0;i--){
            buildHeap(intervals, i, intervals.size()-1);
        }
        ans.push_back(intervals[0]);
        int end = intervals[0][1];
        intervals[0] = intervals.back();
        for(int i=intervals.size()-2;i>=0;i--){
            buildHeap(intervals, 0, i);
            vector<int> tmp = intervals[0];
            if(tmp[0]<=end){
                ans.back()[1] = tmp[1] > end ? tmp[1] : end;
                end = ans.back()[1];
            } else {
                ans.push_back(tmp);
                end = tmp[1];
            }
            intervals[0] = intervals[i];
        }
        return ans;
    }
};
#endif //LEETCODE_56_H
