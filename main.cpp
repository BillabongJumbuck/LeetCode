#include <iostream>
#include "array/11.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;
int main() {
    auto* s = new Solution();
    vector<int> v = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout<< s->maxArea(v) << endl;
    return 0;
}