class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0; // set this as the result, but we know the vector will be non-zero, so we know we will have a value to XOR against
        int numsSize = nums.size();

        // go through the whole vector
        for (int i = 0; i < numsSize; ++i) {
            // we will XOR each element with each following, eventually resulting in only the single-instanced value being put into result
            // as a number XOR'd with itself results in 0. 
            // A (potentially) simple way to think about it is addition/subtraction that flip based on if the value is present in an existing sum or not.
            result ^= nums[i];
        }

        return result;
    }
};