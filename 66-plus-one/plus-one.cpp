class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        std::reverse(digits.begin(), digits.end());

        for (int i = 0; i < size; ++i) {
            int sum = digits[i] + 1;

            if (sum > 9) {
                digits[i] = 0;
                if (i == size - 1) {
                    digits.push_back(1);
                }
            } else {
                digits[i] = sum;
                break;
            }
        }

        std::reverse(digits.begin(), digits.end());
        return digits;
    }
};