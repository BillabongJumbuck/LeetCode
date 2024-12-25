//
// Created by QinJM on 2023/12/3.
//

#ifndef LEETCODE_933_H
#define LEETCODE_933_H
#include <vector>
using namespace std;
class RecentCounter {
    vector<int> request;
public:
    RecentCounter() {
        request.reserve(1e4);
    }

    int ping(int t) {
        request.push_back(t);
        int count = 0;
        for(int i=request.size()-1;i>=0;i--){
            if(request[i] >= t-3000)
                count++;
            else
                break;
        }
        return count;
    }
};

#endif //LEETCODE_933_H
