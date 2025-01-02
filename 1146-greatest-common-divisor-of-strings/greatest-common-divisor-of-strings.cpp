class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        // so str1 should divide into str2 and in a way, vice versa.
        // If that fails, so if they append to each other in order and then in opposite order
        // they should be equal. If not, then we know it's an empty output
        if (str1 + str2 != str2 + str1) {
            return "";
        }

        int len = std::gcd(str1.length(), str2.length());
        return str1.substr(0, len);
    }
};