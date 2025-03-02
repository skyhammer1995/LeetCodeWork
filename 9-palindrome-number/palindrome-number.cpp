class Solution {
public:
    bool isPalindrome(int x) {
        if (isNegative(x)) {
            // will have negative symbol. Example 2 makes it so all negatives are non-palindromes
            return false;
        }
        return isReversedNumberEqual(x);
    }

    bool isReversedNumberEqual(const int& x) {
        // trying the non-string solution
        if (x < 10) {
            // single digits are palindromes, and we already check for negative numbers in this execution flow.
            return true;
        }

        int value = x;
        std::vector<int> numberList;
        while (value > 0) {
            numberList.push_back(value % 10);
            value = value/10;
        }

        std::vector<int>::iterator front = numberList.begin();
        std::vector<int>::iterator back = numberList.end() - 1;
        while (front < back) {
            if ((*front) == (*back)) {
                ++front;
                --back;
            } else {
                return false;
            }
        }

        return true;
    }

    bool isNegative(const int& val) {
        if (val < 0) {
            return true;
        }
        return false;
    }
};