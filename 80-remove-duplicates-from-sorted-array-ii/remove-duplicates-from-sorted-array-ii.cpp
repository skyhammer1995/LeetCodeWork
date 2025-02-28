class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator slow = nums.begin();
        vector<int>::iterator fast = nums.begin() + 1;

        while (fast != nums.end()) {
            if (((*slow) == (*fast)) && 
                (std::distance(slow, fast) > 1)) {
                fast = nums.erase(fast);
            } else if ((*slow) == (*fast)) {
                ++fast;
            } else {
                slow = fast;
                ++fast;
            }
        }

        return nums.size();
    }
};