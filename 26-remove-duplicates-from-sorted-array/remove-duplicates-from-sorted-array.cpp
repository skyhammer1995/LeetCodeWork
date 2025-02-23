class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // base case
        if (nums.size() == 1) {
            return 1;
        }

        std::vector<int>::iterator unique = nums.begin();
        std::vector<int>::iterator current = nums.begin() + 1;

        while (current != nums.end()) {
            if (*current != *unique) {
                // new unique element, move iterator/pointer to where current points
                unique = current; 
                ++current;
            } else if (*current == *unique) {
               // duplicate element, remove duplicate
                current = nums.erase(current);
            }
        }        
        return nums.size();
    }
};