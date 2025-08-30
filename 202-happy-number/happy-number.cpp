// Faster solution after research

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen; // numbers we have already seen

        // break out if we've seen the sum, or if n == 1
        while(n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n); // add the sum to the seen values
            int sum = 0;
            int temp = n;
            while(temp > 0) {
                int digit = temp % 10;  // get last digit
                sum += digit * digit;   // square it and add
                temp /= 10;             // remove last digit
            }
            n = sum; // update n to the sum of squares
        }

        return n == 1; // if 1, happy; else, not happy
    }
};