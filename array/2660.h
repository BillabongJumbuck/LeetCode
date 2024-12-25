//
// Created by QinJM on 2023/12/27.
//

#ifndef LEETCODE_2660_H
#define LEETCODE_2660_H
#include <vector>
using namespace std;
class Solution {
private:
    int score(vector<int> v){
        int ret = 0;
        for(int i=0;i<v.size();i++){
            if((i-2>=0 && v[i-2]==10) || (i-1>=0 && v[i-1]==10))
                ret += 2*v[i];
            else
                ret += v[i];
        }
        return ret;
    }
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = score(player1);
        int score2 = score(player2);
        if(score1 > score2)
            return 1;
        else if(score1 < score2)
            return 2;
        else
            return 0;
    }
};
#endif //LEETCODE_2660_H
