class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // merge vectors
        vector<int> mergedVector(nums1.size() + nums2.size());
        std::merge(nums1.begin(), nums1.end(), 
                   nums2.begin(), nums2.end(), mergedVector.begin());
        
        int length = mergedVector.size();

        if (length % 2 == 1) {
            // odd
            return mergedVector[length/2];
        } else {
            // even
            std::cout << mergedVector[length/2];
            return (mergedVector[length/2] + mergedVector[(length/2)-1]) / 2.0;
        }
    }
};