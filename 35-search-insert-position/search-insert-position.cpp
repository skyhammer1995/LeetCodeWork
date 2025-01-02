class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            // found exactly
            if (nums[i] == target) {
                return i;
            // found its bordering element
            } else if (nums[i] > target) {
                return i;
            } else {
                // I don't need the else, but I'm so used to sonarqube complaining, I just put it in
            }
        }
        // Target is at the end of the vector
        return size;
    }
};