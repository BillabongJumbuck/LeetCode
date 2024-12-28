#include <iostream>
#include "dp/516.h"
using std::cout;
using std::endl;
using std::vector;
int main() {
    auto* s = new Solution();

    cout << s->longestPalindromeSubseq("bbbab") << endl;
    return 0;
}