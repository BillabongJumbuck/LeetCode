#include <iostream>
#include "dp/1289.h"
using std::cout;
using std::endl;
using std::vector;
int main() {
    auto* s = new Solution();
    vector<vector<int>> triangle = {{2,2,1,2,2}, {2,2,1,2,2}, {2,2,1,2,2},{2,2,1,2,2},{2,2,1,2,2}};
    s->minFallingPathSum(triangle);
    return 0;
}