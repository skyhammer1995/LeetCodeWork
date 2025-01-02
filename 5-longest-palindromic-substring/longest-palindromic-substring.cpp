class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // No need to traverse, it's a single char which is palindromic
        if (n < 2) {
            return s;
        }

        int start = 0, maxLength = 1;

        // Start from center, and expand outward left and right
        for (int i = 0; i < n; i++) {
            int left = i, right = i;
            while ((left >= 0 && right < n) && (s[left] == s[right])) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        }
        
        // Need this for even-lengthed inputs
        for (int i = 0; i < n - 1; i++) {
            int left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLength);
    }
};