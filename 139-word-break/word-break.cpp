class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();

        // dp[i] = true if the substring s[0....i-1] can be broken into words from the wordDict, 
        // e.g. "leetcode" w/ ["leet", "code"], d[4] is true since we have "leet", then d[8] would be true.
        // Skip [0], because we're iterating over substring lengths, not indices.
        vector<bool> dp(n + 1, false);
        // base case, empty string can always be segmented
        dp[0] = true;

        // iterate over all positions in string 's'
        for (int i = 1; i <= n; ++i) {
            // check all possible previous split points
            for (int j = 0; j < i;  ++j) {
                // if s[0...j-1] can be segmented (dp[j] == true)
                // AND s[j...i-1] is a word in the dictionary
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true; // then s[0...i-1] can also be segmented
                    break; // break out, since we don't need to check further splits for this i
                }
            }
        }

        return dp[n];
    }
};