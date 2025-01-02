// change approach, since my previous method would have edge case for when 
// a window has single instance prior to current element of a repeat

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxLength = 0;
        int left = 0, right = 0;
        std::unordered_set<char> chars;

        while (right < n) {
            if (chars.find(s[right]) == chars.end()) {
                // We aren't repeating the char that right is pointing at, so insert
                chars.insert(s[right]);
                // After reading up on "sliding window", below seems to be the simplest way to keep track of max programatically
                maxLength = max(maxLength, right - left + 1);
                ++right;
            } else {
                // We are repeating the char that right is pointing to, so we will erase from the left iteratively until that becomes false
                chars.erase(s[left]);
                ++left;
            }
        }

        return maxLength;
    }
};