//
// Created by QinJM on 2023/11/29.
//

#ifndef LEETCODE_2336_H
#define LEETCODE_2336_H
#include <set>
using namespace std;
class SmallestInfiniteSet {
private:
    int lowerBound;
    set<int> s;
public:
    SmallestInfiniteSet() {
        lowerBound = 1;
    }

    int popSmallest() {
        int ret;
        if(s.empty()){
            ret = lowerBound;
            lowerBound++;
        }else{
            ret = *s.begin();
            s.erase(s.begin());
        }
        return ret;
    }

    void addBack(int num) {
        if(num<lowerBound){
            s.insert(num);
        }
    }
};
#endif //LEETCODE_2336_H
