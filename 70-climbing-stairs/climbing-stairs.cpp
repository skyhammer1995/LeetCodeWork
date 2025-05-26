class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }

        int one = 1;
        int two = 2;

        // tbh people mentioned fibonacci sequence as a hint, so still not sure this is the best way
        for (int i = 3; i <= n; ++i) {
            int current = one + two;
            one = two;
            two = current;
        }

        return two;
    }
};