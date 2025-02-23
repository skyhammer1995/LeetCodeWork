class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Second attempt, reduce
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[k-1]) {
                nums[k] = nums[i];
                ++k;
            }
        }

        return k;
    }
};