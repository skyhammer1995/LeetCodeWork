class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::unordered_map<int, int> freqMap;
        int maxValue = 0;
        int maxKey; 

        for (const int& num : nums) {
            freqMap[num]++;
        }

        for (const auto& pair : freqMap) {
            if (maxValue < pair.second) {
                maxValue = pair.second;
                maxKey = pair.first;
            }
        }

        return maxKey;
    }
};