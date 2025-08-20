// x - '0' converts the string into its ascii index 1:1 with its integer
// x + '0' converts the index back into ascii
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
    
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry) {
            int bitA = (i >= 0) ? a[i] - '0' : 0;
            int bitB = (j >= 0) ? b[j] - '0' : 0;

            // XOR everything to get the current sum
            int sum = bitA ^ bitB ^ carry;            
            // Assign carry new value if needed
            carry = (bitA & bitB) | (carry & (bitA ^ bitB));

            // push the results to string
            result.push_back(sum + '0');
            
            // decrement
            --i;
            --j;
        }

        //because we pushed back on 
        reverse(result.begin(), result.end());

        return result;
    }
};