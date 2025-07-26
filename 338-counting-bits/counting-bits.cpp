class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        // 0th element is always going to be 0
        ans[0] = 0;

        for (int i = 1; i <= n; ++i) {
            // if i is even, the number of 1s in i is the same as the number of 1s in i/2
            // if i is odd the number of 1s in i is the same as the number of 1s in i-1 plus 1 more.
            ans[i] = ((i%2 == 0) ? ans[i/2] : ans[i-1] + 1);
            // could also do ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};