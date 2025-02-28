class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int> tempHolder;
        int remainderRotations = k%nums.size();

        if (remainderRotations == 0) {
            // no need to rotate
            return;
        }

        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + remainderRotations);
        std::reverse(nums.begin() + remainderRotations, nums.end());
    }
};