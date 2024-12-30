#include <iostream>
#include "dp/712.h"
#include <vector>

using std::cout;
using std::endl;
using std::vector;
int main() {
    auto* s = new Solution();
    cout<< s->minimumDeleteSum("sea", "eat") << endl;
    return 0;
}