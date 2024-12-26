#include <iostream>
#include "array/3159.h"
using std::cout;
using std::endl;
using std::vector;
int main() {
    auto* s = new Solution();
    vector<int> nums = {1, 3, 1, 7};
    vector<int> queries = {1, 3 , 2 ,4};
    int x = 1;
    s->occurrencesOfElement(nums, queries, x);
    return 0;
}