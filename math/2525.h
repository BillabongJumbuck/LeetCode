//
// Created by QinJM on 2023/10/20.
//

#ifndef LEETCODE_2525_H
#define LEETCODE_2525_H
#include <string>
using namespace std;
class Solution {
private:
    long long getVolume(int length, int width, int height){
        return 1L * length * width * height;
    }
    bool isBulky(int length, int width, int height){
        if( length >=10000 || width >= 10000 || height >= 10000 || getVolume(length, width, height) >=1000000000)
            return true;
        return false;
    }
    bool isHeavy(int mass){
        if(mass >= 100)
            return true;
        return false;
    }
public:
    string categorizeBox(int length, int width, int height, int mass) {
        if(isBulky(length, width, height) && isHeavy(mass))
            return "Both";
        else if(isBulky(length, width, height))
            return "Bulky";
        else if(isHeavy(mass))
            return "Heavy";
        else
            return "Neither";
    }
};
#endif //LEETCODE_2525_H
