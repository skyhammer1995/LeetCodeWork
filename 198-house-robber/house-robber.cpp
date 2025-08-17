// trying to think this out. Go through vector one time to get the values "case the joints",
// I don't think this would be sliding window or anything like that, 
// and we can't be greedy necessarily (metaphorically and code context wise).
class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0; // dp[i-1]
        int prev2 = 0; // dp[i-2]

        for (int money : nums) {
            int rob = prev2 + money;
            int skip = prev1;
            int curr = max(rob, skip);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};