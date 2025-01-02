class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int maxReach = 0;

        for (int i = 0; i < size; i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = std::max(maxReach, i + nums[i]);
            if (maxReach >= size - 1) {
                return true;
            }
        }
        return false;  
    }
};