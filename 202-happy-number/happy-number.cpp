class Solution {
public:
    bool isHappy(int n) {
        std::map<int, int> predefinedSquares = {
            {0, 0},
            {1, 1},
            {2, 4},
            {3, 9},
            {4, 16},
            {5, 25},
            {6, 36},
            {7, 49},
            {8, 64},
            {9, 81}
        };

        // isolate the numerals, and then square them
        // take their sum, and then repeat the process
        // once we have a sum 1 break?
        
        // For the failure case, we probably need to throw the values of evaluated sums into a hashmap
        // if we see a repeat, we know we won't be happy, because we are cycling
        std::unordered_map<int, bool> visitedNumbers;
        
        while (true) {
            std::vector<int> digitVector = extractDigits(n);
            int sum = 0;

            for (auto digit : digitVector) {
                sum += predefinedSquares[digit];
            } 

            if (sum == 1) {
                break; 
                // I would return true here, but I think having a root-based return true is better
            } else if (visitedNumbers[sum] == true) {
                // we can use zero-initialization of bool with this, so if we check a new sum, we're safe with the [] operator
                // otherwise, if we hit true here, we have seen the number before, we can return false
                return false;
            } else {
                visitedNumbers[sum] = true;
            }

            n = sum;
        } 

        return true;               
    }

    std::vector<int> extractDigits(int n) {
        // We have to get the numbers into a vector(?)
        std::vector<int> digits;
        while (n > 0) {
            // Just directly push, and we can just modify n, I don't think we need to preserve
            digits.push_back(n % 10);
            // get rid of the last digit by dividing by 10 
            n /= 10;
        }

        return digits;
    }
};