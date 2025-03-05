class Solution {
public:
    string reverseWords(string s) {
        string result;
        vector<std::string> stringVector;
        bool workingOnWord = false;
        string::const_iterator slow = s.begin();
        string::const_iterator fast = s.begin();

        // step through and remove any extra spaces, push words to vector?
        while (fast != s.end()) {
            if (*fast == ' ') {
                if (workingOnWord) {
                    stringVector.push_back(std::string(slow, fast));
                    workingOnWord = false;
                }
            } else {
                if (!workingOnWord) {
                    // skip leading spaces
                    slow = fast;
                    workingOnWord = true;
                }
            }

            if (std::next(fast) == s.end() && workingOnWord) {
                // handle last word at the end
                stringVector.push_back(std::string(slow, s.cend()));
            }
            ++fast;
        }

        for (std::vector<string>::const_reverse_iterator rIt = stringVector.crbegin(); rIt != stringVector.crend(); ++rIt) {
            result += *rIt;
            // keep adding space in between until we reach the last word
            if (std::next(rIt) != stringVector.crend()) {
                result += " ";
            }
        }

        return result;
    }
};