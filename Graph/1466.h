//
// Created by QinJM on 2023/12/7.
//

#ifndef LEETCODE_1466_H
#define LEETCODE_1466_H
#include <vector>
#include <set>
using namespace std;
class Solution {
private:
    void swap(int *a, int *b){
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int count = 0;
        set<int> reached = {0};
        while(reached.size() != n){
            for(auto i : connections){
                if(reached.find(i[0]) == reached.end() && reached.find(i[1]) != reached.end()){
                    count++;
                    reached.insert(i[0]);
                    swap(&i[0], &i[1]);
                }
            }
        }
        return count;
    }
};
#endif //LEETCODE_1466_H
