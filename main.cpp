#include <iostream>
#include "dp/139.h"
using std::cout;
using std::endl;
using std::vector;
int main() {
    auto* s = new Solution();
    vector<string> w = {"cats","dog","sand","and","cat"};
    cout << s->wordBreak("catsandog", w) << endl;
    return 0;
}