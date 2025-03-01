class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return 0;
        }

        int jumps = 0;
        int maxReach = 0;
        int currentEnd = 0;

        for (int i = 0; i < size - 1; ++i) {
            maxReach = std::max(maxReach, i + nums[i]);

            if (i == currentEnd) {
                ++jumps;
                currentEnd = maxReach;
                
                if (currentEnd >= size - 1) {
                    return jumps;
                }
            }
        }
        return jumps;
    }
};