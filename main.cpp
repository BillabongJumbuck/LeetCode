#include <iostream>
#include "dp/5.h"

int main() {
    auto* s = new Solution();
    string test = "babad";
    cout<<s->longestPalindrome(test)<<endl;
    return 0;
}