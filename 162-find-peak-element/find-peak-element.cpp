class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                // slope is up, move right
                left = mid + 1;
            } else {
                // slope is down or peak, move left (including mid)
                right = mid;
            }
        }

        // left == right peak
        return left;
    }
};