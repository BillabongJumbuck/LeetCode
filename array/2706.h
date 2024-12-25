//
// Created by QinJM on 2023/12/29.
//

#ifndef LEETCODE_2706_H
#define LEETCODE_2706_H
#include <vector>
using namespace std;
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int a = 100;
        int b = 100;
        for(int i : prices){
            if(i<a){
                b = a;
                a = i;
            }else if(i<b){
                b = i;
            }
        }
        return (money-a-b >= 0 ? money-a-b : money);
    }
};
#endif //LEETCODE_2706_H
