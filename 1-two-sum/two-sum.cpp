class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> resultMap;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (resultMap.count(complement)) {
                return {resultMap[complement], i};
            }
            // if the complement isn't found above, throw the num[i] element into the map as the key, and the current index of the vector as the element into the hash map.
            resultMap[nums[i]] = i;
        }
        return {}; // no solution was found
    }
};