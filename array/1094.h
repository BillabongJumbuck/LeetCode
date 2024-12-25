//
// Created by QinJM on 2023/12/2.
//

#ifndef LEETCODE_1094_H
#define LEETCODE_1094_H
#include <vector>
#include <map>
#include <iterator>
using namespace std;
struct ifo{
    int station;
    bool on_or_off;
    ifo() = default;
    ifo(int x, bool y) : station(x), on_or_off(y) {}
};
struct com_fun{
    bool operator()(const ifo& item1,const ifo& item2) const {
        if (item1.station != item2.station)
            return item1.station < item2.station;
        else
            return !item1.on_or_off;
    }
};
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity){
        multimap<ifo, int, com_fun> station;
        for(const auto& i : trips){
            ifo tmp1(i[1], true);
            station.insert({tmp1, i[0]});
        }
        int size = 0;
        for(const auto& i : station){
            if(i.first.on_or_off == false){
                size -= i.second;
            }else{
                size += i.second;
                if(size>capacity)
                    return false;
            }
        }
        return true;
    }
};
#endif //LEETCODE_1094_H
