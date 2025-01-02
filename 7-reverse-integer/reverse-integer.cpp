class Solution {
public:
    int reverse(int x) {
        int reverseNum = 0;
        bool negative = false;
        if (x < 0) {
            negative = true;
            if (x < (INT_MAX * -1)) {
                return 0;
            }
            x = x * -1;
        }

        while (x > 0) {
            int pop = x % 10;
            x = x/10;
            if (reverseNum > INT_MAX/10 || (reverseNum == INT_MAX/10 && x > 7)) {
                return 0;
            }
            if (reverseNum < INT_MIN/10 || (reverseNum == INT_MIN/10 && x < -8)) {
                return 0;
            }
            reverseNum = reverseNum * 10 + pop;
        }

        return negative ? (-1 * reverseNum) : reverseNum;
    }
};