class Solution {
public:
    int hammingWeight(int n) {
        int count;

        // "iterate" over integer n by 
        // n = n & n - 1; 
        // e.g. if we have 11, n - 1 is 10, 
        // so iteration/count 1 is 11 in binary: 1011 and 10 in binary: 1010, 
        // when we do 11 & 10 we end up with 10, and continue until n is 0 (we will evaluate to false and exit the for loop)
        // to continue with the example:
        // iteration/count 2 is n = 10: 1010, n-1 = 9: 1001, result is 1000 or 8
        // iteration/count 3 is n = 8: 1000, n-1 = 7:  0111, result is 0 -- we will exit our for loop on the next check.
        // Count is 3 once we exit. Compared with our orignal n 11: 1011, is correct.
        
        while(n) {       
            n &= n - 1;
            count++;
        }
            
        return count;
    }
};