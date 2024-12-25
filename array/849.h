//
// Created by QinJM on 2023/12/19.
//

#ifndef LEETCODE_849_H
#define LEETCODE_849_H
#include <vector>
using namespace std;
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int space = 0;
        int first = 0;
        for(;first<seats.size();++first){
            if(seats[first] == 1)
                break;
        }
        int ans = first;
        for(int i=first;i<seats.size();i++){
            if(seats[i]==1){
                int tmp = (space+1)/2;
                if(tmp > ans)
                    ans = tmp;
                space = 0;
            }else{
                space++;
            }
        }
        if(space > ans)
            ans = space;
        return ans;
    }
};
#endif //LEETCODE_849_H
