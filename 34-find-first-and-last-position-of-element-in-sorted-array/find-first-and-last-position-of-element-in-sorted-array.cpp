class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        std::vector<int>::iterator front = std::find(nums.begin(), nums.end(), target);
        std::vector<int>::reverse_iterator back = std::find(nums.rbegin(), nums.rend(), target);

        if (front != nums.end() && back != nums.rend()) {
            std::vector<int> result;
            result.push_back(std::distance(nums.begin(), front));
            result.push_back(std::distance(back, nums.rend() - 1));
            return result;
        }
        return {-1, -1};
    }
};