#include <iostream>
#include "dp/5.h"

int main() {
    auto* s = new Solution();
    string test = "aacabdkacaa";
    cout<<s->longestPalindrome(test)<<endl;
    return 0;
}