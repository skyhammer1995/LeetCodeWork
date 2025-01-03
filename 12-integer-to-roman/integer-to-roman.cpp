#include <map>
#include <algorithm>

class Solution {
public:
    string intToRoman(int num) {
        std::string result {};
        int numOfLetters = 0;
        std::map<int, std::string>::reverse_iterator mapIt = m_numToRoman.rbegin();
        while (num > 0) {
            int q = num/(mapIt->first);
            num = num%(mapIt->first);

            // append string in second element a number of times equal to q
            while (q--) {
                // I wish I could use the fill constructor, but alas, it doesn't support strings, only char types
                // so we have this while loop to do the append a number of times instead.
                result.append(mapIt->second);
            }
            // let's move up the map since we should have placed as many roman numerals as possible with 
            // current quotient
            ++mapIt;
        }
        return result;
    }

private: 
    // I'm really confused why it's not initializing with this list
    std::map<int, std::string> m_numToRoman = {
                                        {1, "I"},
                                        {4, "IV"},
                                        {5, "V"},
                                        {9, "IX"},
                                        {10, "X"},
                                        {40, "XL"},
                                        {50, "L"},
                                        {90, "XC"},
                                        {100, "C"},
                                        {400, "CD"},
                                        {500, "D"},
                                        {900, "CM"},
                                        {1000, "M"}
                                        };
};