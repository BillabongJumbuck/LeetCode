//
// Created by QinJM on 2023/12/10.
//

#ifndef LEETCODE_231210_01_H
#define LEETCODE_231210_01_H
#include <vector>
using namespace std;
class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int ret = 0;
        for(int i=0;i<batteryPercentages.size();i++){
            if(batteryPercentages[i] - ret > 0){
                ret++;
            }else{
                continue;
            }
        }
        return ret;
    }
};
#endif //LEETCODE_231210_01_H
