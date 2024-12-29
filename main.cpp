#include <iostream>
#include "heap/1366.h"
using std::cout;
using std::endl;
using std::vector;
int main() {
    auto* s = new Solution();
    vector<string> v = {"ABC","ACB","ABC","ACB","ACB"};
    vector<string> v2 = {"ZMNAGUEDSJYLBOPHRQICWFXTVK"};
    cout<< s->rankTeams(v2) << endl;
    return 0;
}