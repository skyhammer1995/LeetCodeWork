class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // number of permutations determined by nums!/(nums-nums)! ~= nums!  (in this case)
        vector<vector<int>> permutations;
        int n = nums.size();

        vector<int> currentPermutation(n); // all permutations are the same size as nums
        vector<bool> visited(n, false); // initialize vector of size n, and set all to false

        std::function<void(int)> dfs = [&](int depth) {
            if (depth == n) {
                permutations.emplace_back(currentPermutation);
                return;
            }
            for (int i = 0; i < n; ++i) {
                if (!visited[i]) {
                    visited[i] = true;
                    currentPermutation[depth] = nums[i]; // set value in current permutation
                    dfs(depth + 1); // Recurse next depth
                    visited[i] = false; // unmarks as visited for backtracking
                }
            }
        };

        dfs(0);
        return permutations;
    }
};