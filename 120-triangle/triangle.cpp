class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {    
        int numberOfRows = triangle.size();
        
        // Get elements from the last and put them in the Dr. Pepper :p vector
        vector<int> dp = triangle.back();
        
        // I'm thinking about how to navigate this triangle...    
        
        // after reflecting, the intuition algo was bad due to greedy pitfall. 
        // we can start from the bottom, check the min between each point above, sum, 
        // and keep working our way up to the top
        
        for (int i = numberOfRows - 2; i >= 0; --i) {
            // we can skip the last row, and start at next to last, hence the minus 2
            int sizeOfRow = triangle[i].size();
            for (int j = 0; j < sizeOfRow; ++j) {
                // navigate across the row

                // we will take the current triangle value, add it to the minimum of the two values of the row below (that we could path to)
                // and update the value of the dp vector/array. We will essentially "abandon" the backth element each time we ascend.
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
            }
        }

        // dp[0] will always hold the minimum path sum
        return dp[0];
    }
};