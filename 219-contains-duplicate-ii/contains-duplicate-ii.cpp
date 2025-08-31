class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window; // store last k elements
        
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (window.count(nums[right])) {
                // if we find the same number, and it is within our window
                return true;
            }

            window.insert(nums[right]);

            if ((right - left) >= k) {
                // we want to decrease the window size to keep it <= k
                window.erase(nums[left]);
                left++;
            }
        }

        return false;
    }
};