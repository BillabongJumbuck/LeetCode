//
// Created by QinJM on 24-12-29.
//

#ifndef LEETCODE_1366_H
#define LEETCODE_1366_H
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    struct Node{
        char index = '\0';
        vector<int> rank;
    };
public:
    string rankTeams(vector<string>& votes) {
        vector<Node> v(26);
        string& s0 = votes.front();
        int size = s0.size();
        for (auto& node : v) {
            node.rank.resize(size, 0);
        }
        for (const auto& vote : votes) {
            for (int j = 0; j < size; ++j) {
                v[vote[j] - 'A'].index = vote[j];
                v[vote[j] - 'A'].rank[j]++;
            }
        }
        std::sort(v.begin(), v.end(), [size](Node &node1, Node &node2)->bool {
            if (node1.index == '\0') return false;
            if (node2.index == '\0') return true;

            for(int i=0;i<size;i++){
                if(node1.rank[i] > node2.rank[i])
                    return true;
            }
            return false;
        });
        string res;
        for(int i=0;i<size;i++){
            res += v[i].index;
        }
        return res;
    }
};
#endif //LEETCODE_1366_H
