int removeElement(int* nums, int numsSize, int val) {
    int k = 0; // keep track of our elements that do NOT equal val

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) { // if the current element does not equal val, we're going to move it to the kth element 
            nums[k] = nums[i]; // overwrite in place
            k++; // increase the number of elements that do not equal
        }
    }

    return k;
}