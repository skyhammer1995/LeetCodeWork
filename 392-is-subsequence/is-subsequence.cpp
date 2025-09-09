class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPointer = 0;
        int tPointer = 0;
        size_t sSize = s.size();
        size_t tSize = t.size();


        if (sSize > tSize) {
            // s cannot be a substring of t while it is bigger than t
            return false;
        }

        while (sPointer < sSize) {
            // check if tPointer is greater than or equal to t's size
            if (tPointer >= tSize) {
                // we've gone through and not found a match, so we must not be able to have a substring
                return false;
            }
            
            if (s[sPointer] == t[tPointer]) {
                // we match, we can iterate on both
                ++sPointer;
                ++tPointer;
            } else {
                // we don't match, iterate on t
                ++tPointer;
            }
        }

        return true;
    }
};