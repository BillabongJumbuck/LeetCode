//
// Created by QinJM on 2023/12/21.
//

#ifndef LEETCODE_2866_H
#define LEETCODE_2866_H
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int max_index = 0;
        int max_num = 0;
        for(int i=0;i<maxHeights.size();i++){
            if(maxHeights[i]>max_num){
                max_index = i;
                max_num = maxHeights[i];
            }
        }
        for(int left = max_index-2;left>=0;left--){
            if(maxHeights[left]>maxHeights[left+1])
                maxHeights[left] = maxHeights[left+1];
        }
        for(int right = max_index+2;right<maxHeights.size();right++){
            if(maxHeights[right]>maxHeights[right-1])
                maxHeights[right] = maxHeights[right-1];
        }
        int ans = 0;
        for(int maxHeight : maxHeights){
            ans += maxHeight;
        }
        return ans;
    }
};
#endif //LEETCODE_2866_H
