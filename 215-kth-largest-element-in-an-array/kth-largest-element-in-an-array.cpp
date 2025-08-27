class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // min-heap, smallest element at top()
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // go through each number in the nums vector
        for (auto num : nums) {
            // push each number onto the heap
            minHeap.push(num);
            // check if the size of the heap is greater than k
            if (minHeap.size() > k) {
                // because the size is greater, we know that we need to get rid of the top
                minHeap.pop();
            }

            // we will repeat, loading the smallest values to the top. 
            // At the end, we should have a heap that has k elements, thus the kth element, should be at top()
        }

        return minHeap.top();
    }
};