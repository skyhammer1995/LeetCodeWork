#include <map>
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int currentMax = 0;
        std::reverse(s.begin(), s.end());

        for (const char& c : s) {
        //     if (m_symbolToInt.find(c) == m_symbolToInt.end()) {
        //         // LOGERROR(), stating that there are non-roman chars in the string
        //         // return -1/some agreed upon failure value?
        //     }

            if (m_symbolToInt.at(c) < currentMax) {
                result -= m_symbolToInt.at(c);
            } else {
                result += m_symbolToInt.at(c);
                currentMax = m_symbolToInt.at(c);
            }
        }
        return result;
    }
private: 
    std::map<char, int> m_symbolToInt = {{'I', 1},
                                         {'V', 5},
                                         {'X', 10},
                                         {'L', 50},
                                         {'C', 100},
                                         {'D', 500},
                                         {'M', 1000}};
};