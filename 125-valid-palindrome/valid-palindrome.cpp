#include <cctype> // for isalnum - I think this is ok in this context, but I guess if it weren't allowed, I'd create an unordered_set of all numerals and letters to check against.

class Solution {
public:
    bool isEqualIgnoreCharCase(char a, char b) {
        // in 20, or with cctype I would just use tolower(), but I think here, this is to practice with manual order of ASCII
        if (a >= 'A' && a <= 'Z') {
            // convert to lowercase
            a += 32;  
        }
        if (b >= 'A' && b <= 'Z') {
            // convert to lowercase
            b += 32;  
        }

        return a == b;
    }

    bool isPalindrome(string s) {
        if (s.empty()) {
            // empty string is true
            return true;
        }
        
        // Do we need to remove all non-alphanumeric characters ahead of time? Checking at each char wouldn't really be expensive I think
        int left = 0;
        int right = s.size() - 1;


        // We will start at the beginning and end of the string, if there's ever a time when there isn't a match between two elements then we will
        while (left < right) {
            // check if left element is alphanumeric, if not, decrement on left until it is
            if (!isalnum(s[left])) {
                ++left;
                continue; // I don't love putting continues, but right now it's the only way I can think of to do this, I'm sure there's a more algorithmically pretty way.
            }
            // check if right element is alphanumeric, if not, decrement on right until it is
            if (!isalnum(s[right])) {
                --right;
                continue;
            }

            if (!isEqualIgnoreCharCase(s[left], s[right])) {
                // we don't have a matching char--so not a palindrome
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};