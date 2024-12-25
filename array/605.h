//
// Created by QinJM on 2023/9/29.
//

#ifndef LEETCODE_605_H
#define LEETCODE_605_H
#include <vector>
using namespace std;
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0, num = 0, i = 0;
        for(;i<flowerbed.size()-1;++i){
            if(flowerbed[i]==0)
                ++count;
            else
                break;
        }
        num += count/2;
        count = 0;
        flowerbed.push_back(0);
        flowerbed.push_back(1);
        for(;i<flowerbed.size()-1;++i){
            if(flowerbed[i] == 0)
                ++count;
            else{
                num += (count-1)/2;
                count == 0;
            }
        }
        flowerbed.pop_back();
        flowerbed.pop_back();
        if(count>=n)
            return true;
        else
            return false;
    }
};
#endif //LEETCODE_605_H
