class Solution {
public:
    int trailingZeroes(int n) {
        int numberOfTrailingZeroes = 0;

        while (n >= 5) {
            // we divide by 5
            n /= 5;
            // add new value to the existing trailing sum
            numberOfTrailingZeroes += n;
        }

        return numberOfTrailingZeroes;
    }
};