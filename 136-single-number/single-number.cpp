class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0; // set this as the result, but we know the vector will be non-zero, so we know we will have a value to XOR against
        int numsSize = nums.size();

        // go through the whole vector
        for (int i = 0; i < numsSize; ++i) {
            // we will XOR each element with each following, eventually resulting in only the single-instanced value being put into result
            result ^= nums[i];
        }

        return result;
    }
};