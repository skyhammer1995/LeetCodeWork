#include <map>
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        std::vector<string> result = {""};

        for (const char& digit : digits) {
            std::vector<string> tmp;
            for (std::string& currStr : result) {
                for (char c : m_numbersToLetters.at(digit)) {
                    tmp.push_back(currStr + c);
                }
            }
            result = tmp;
        }

        return result;
    }
private:
    std::unordered_map<char, std::string> 
        m_numbersToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

};