class Solution {
public:
    int myAtoi(string s) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Skip leading whitespace
    while (s[i] == ' ') {
        i++;
    }

    // Check for sign
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    // Read digits
    while (s[i] >= '0' && s[i] <= '9') {
        // Check for overflow
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + (s[i] - '0');
        i++;
    }

    return result * sign;

    }
};