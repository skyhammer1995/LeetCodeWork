class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // get the words out of s
        vector<string> words;
        string word; 
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }

        if (words.size() != pattern.size()) {
            return false;
        }

        unordered_map<string, char> wordToChar;
        unordered_map<char, string> charToWord;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (charToWord.count(c)) {
                // letter is already within charToWord
                if (charToWord[c] != w) {
                    // paired word doesn't match current word
                    return false;
                } 
            } else {
                // pair the letter and word
                charToWord[c] = w;
            }

            if (wordToChar.count(w)) {
                // word is already within wordToChar
                if (wordToChar[w] != c) {
                    // paired letter doesn't match current letter
                    return false;
                }
            } else {
                // pair word and letter
                wordToChar[w] = c;
            }
        }
        return true;
    }
};