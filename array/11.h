//
// Created by QinJM on 2023/12/12.
//

#ifndef LEETCODE_11_H
#define LEETCODE_11_H
#include <vector>
using std::vector;
using std::max;
using std::min;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int max_area = 0;
        while(left<right){
            max_area = max(max_area, min(height[left], height[right]) * (right-left));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return max_area;
    }
};
#endif //LEETCODE_11_H
