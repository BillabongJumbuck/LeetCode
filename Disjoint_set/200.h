//
// Created by QinJM on 2023/12/16.
//

#ifndef LEETCODE_200_H
#define LEETCODE_200_H
#include <vector>
using namespace std;
class Solution {
private:
    vector<int> set;
    void create_set(int capacity){
        set = vector(capacity, -1);
    }
    int find(int x){
        for(;set[x]>=0;x=set[x]);
        return x;
    }
    void merge(int root1, int root2){
        if (root1 == root2) {
            return;
        } else if (set[root2] < set[root1]) {
            set[root2] += set[root1];
            set[root1] = root2;
        } else {
            set[root1] += set[root2];
            set[root2] = root1;
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        create_set(n*m);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0'){
                    set[i*m+j]=0;
                }else{
                    if(i-1>=0 && grid[i-1][j]=='1'){
                        merge(find((i-1)*m+j), find(i*m+j));
                    }
                    if(j-1>=0 && grid[i][j-1] == '1'){
                        merge(find(i*m+j), find(i*m+j-1));
                    }
                    if(i+1<n && grid[i+1][j]=='1'){
                        merge(find((i+1)*m+j), find(i*m+j));
                    }
                    if(j+1<m && grid[i][j+1]=='1'){
                        merge(find(i*m+j), find(i*m+j+1));
                    }
                }
            }
        }
        for(int i=0;i<set.size();i++) {
            if (set[i] < 0)
                ans++;
        }
        return ans;
    }
};
#endif //LEETCODE_200_H
