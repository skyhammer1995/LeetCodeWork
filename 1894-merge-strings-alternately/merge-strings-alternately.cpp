class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        std::string::iterator word1It = word1.begin();
        std::string::iterator word2It = word2.begin();
        std::string mergedString = "";

        while (word1It != word1.end() && word2It != word2.end()) {
            // add current word1 element
            mergedString += *word1It;
            // add current word2 element
            mergedString += *word2It;
            // iterate current word1 and word2 iterators
            ++word1It;
            ++word2It;
        }

        if (word1It != word1.end()) {
            // word1 is larger, append the rest to the merged string
            mergedString.append(word1It, word1.end());
        } else if (word2It != word2.end()) {
            // word2 is larger append the rest to the merged string
            mergedString.append(word2It, word2.end());
        } else {
            // we don't need to do anything, since both are equal size
        }

        return mergedString;
    }
};