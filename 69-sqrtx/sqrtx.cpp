class Solution {
public:
    int mySqrt(int x) {
        long result = 0;
        while (true) {
            if (result * result > x) {
                // we know it's the previous iteration of result
                result -= 1;
                break;
            }
            ++result;
        }

        return result;
    }
};