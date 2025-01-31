class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = nums[0] + nums[1] + nums[2]; // Initialize with the first valid sum
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n-2; i++) {
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (std::abs(sum - target) < std::abs(result - target)) {
                    result = sum;
                }

                if (sum == target) {
                    return (sum);
                } else if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                }
            }
        }
        return result;
    }
};