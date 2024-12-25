//
// Created by QinJM on 2023/12/12.
//

#ifndef LEETCODE_11_H
#define LEETCODE_11_H
#include <vector>
using std::vector;
class Solution {
private:
    inline int min(int a, int b){
        return (a>b?b:a);
    }
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for(int i=0;i<height.size();i++){
            for(int j=i+1;j<height.size();j++){
                int tmp = min(height[i],height[j]) * (j-i);
                if(tmp > ans)
                    ans = tmp;
            }
        }
        return ans;
    }
};
#endif //LEETCODE_11_H
