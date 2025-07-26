class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer(2);
        unordered_map<int, std::pair<bool, bool>> counterMap;
        size_t size1 = nums1.size();
        size_t size2 = nums2.size();
        size_t maxSize = max(nums1.size(), nums2.size()); // constraints make me think this is needed since we can have different sized params
        
        // load the map and we can say whether or not an element is in nums1 and/or nums2
        // added the i < size checks for preventing when we go out of scope for when the vectors don't have the same size
        for (int i = 0; i < maxSize; ++i) {
            if ((i < size1) && counterMap[nums1[i]].first == false) {
                counterMap[nums1[i]].first = true;
            }
            if ((i < size2) && counterMap[nums2[i]].second == false) {
                counterMap[nums2[i]].second = true;
            }
        }

        // go through the generated map, now that we've gone through both nums 1 and 2, and populate unique keys to the answer vector of vectors
        for (auto it : counterMap) {
            if (it.second.first == true && it.second.second == false) {
                // element is only in nums1
                answer[0].push_back(it.first);
            } else if (it.second.first == false && it.second.second == true) {
                // element is only in nums2
                answer[1].push_back(it.first);
            } else {
                // found in both, do-nothing
            }
        }

        return answer;
    }
};