class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;
        
        for (int i = 0; i < 32; ++i) {
            ans = ans << 1;      // Shift 'ans' left to make room for the next bit

            if (n & 1) {         // Check if the last bit of 'n' is 1
                ans = ans | 1;   // If so, set the last bit of 'ans' to 1
            }

            n = n >> 1;          // Move 'n' right to check its next bit
        }

        return ans;
    }
};