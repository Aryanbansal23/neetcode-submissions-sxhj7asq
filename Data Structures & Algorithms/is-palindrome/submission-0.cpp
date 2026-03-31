#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int b = 0, e = s.length() - 1;
        
        while (b <= e) {
            // Ignore non-alphanumeric characters
            while (b < e && !isalnum(s[b])) b++;
            while (b < e && !isalnum(s[e])) e--;

            // Compare characters case-insensitively
            if (tolower(s[b]) != tolower(s[e])) {
                return false;
            }
            b++;
            e--;
        }
        
        return true;
    }
};

