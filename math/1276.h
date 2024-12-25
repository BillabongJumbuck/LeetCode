//
// Created by QinJM on 2023/12/25.
//

#ifndef LEETCODE_1276_H
#define LEETCODE_1276_H
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ret;
        double x = (tomatoSlices-2*cheeseSlices)*0.5;
        double y = (4*cheeseSlices-tomatoSlices)*0.5;
        if(x>=0 && y>=0){
            if(x-static_cast<int>(x)==0 && y-static_cast<int>(y)==0){
                ret.push_back(static_cast<int>(x));
                ret.push_back(static_cast<int>(y));
            }
        }
        return ret;
    }
};
#endif //LEETCODE_1276_H
