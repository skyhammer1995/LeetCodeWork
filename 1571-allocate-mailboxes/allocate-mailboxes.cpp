class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end()); // Sort houses first

        // Step 1: Compute cost[i][j] - Cost of placing a mailbox for houses[i] to houses[j]
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int medianIndex = (i + j) / 2; // Median minimizes distance
                for (int m = i; m <= j; m++) {
                    cost[i][j] += abs(houses[m] - houses[medianIndex]);
                }
            }
        }

        // Step 2: DP Table, dp[i][j] = minimum distance using j mailboxes for first i houses
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));

        // Base case: No houses → Cost is 0
        for (int j = 0; j <= k; j++) dp[0][j] = 0;

        // Step 3: DP Transition
        for (int j = 1; j <= k; j++) {  // Number of mailboxes
            for (int i = 1; i <= n; i++) {  // Number of houses considered
                for (int m = 0; m < i; m++) {  // Try different partitions
                    if (dp[m][j - 1] != INT_MAX) {  // Avoid unnecessary computations
                        dp[i][j] = min(dp[i][j], dp[m][j - 1] + cost[m][i - 1]);
                    }
                }
            }
        }

        return dp[n][k];  // Answer: Minimum total distance for all n houses with k mailboxes
    }
};