#include <iostream>
#include "Hash/2610.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;
int main() {
    auto* s = new Solution();
    vector<int> v = {1,3,4,1,2,3,1};
    s->findMatrix(v);
    return 0;
}