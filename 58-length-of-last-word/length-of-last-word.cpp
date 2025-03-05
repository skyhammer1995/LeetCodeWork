class Solution {
public:
    int lengthOfLastWord(string s) {
        int countResult = 0;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            if (*it == ' ') {
                // we've either hit a space beyond or behind the final word
                if (countResult != 0) {
                    // we've been counting a word, break out and just return our count
                    break;
                } 
            } else {
                // we've hit a letter, not space, so iterate count
                ++countResult;       
            }
        }

        return countResult;
    }
};