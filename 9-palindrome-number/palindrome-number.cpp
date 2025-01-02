class Solution {
public:
    bool isPalindrome(int x) {
        if (isNegative(x)) {
            // will have negative symbol. Example 2 makes it so all negatives are non-palindromes
            return false;
        }
        // Thoughts at this point: I think we can just reverse the number,
        // if equal, we have a palindrome, otherwise false.
        return isReversedNumberEqual(x);
    }

    bool isReversedNumberEqual(const int& x) {
        std::string numberInString = std::to_string(x);
        std::reverse(numberInString.begin(), numberInString.end());
        // we change to long, to avoid overflow runtime errors
        int reversedNumber = std::stol(numberInString);

        if (reversedNumber == x) {
            return true;
        }
        return false;        
    }

    bool isNegative(const int& val) {
        if (val < 0) {
            return true;
        }
        return false;
    }
};