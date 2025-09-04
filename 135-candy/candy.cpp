class Solution {
public:
    int candy(vector<int>& ratings) {
        int result = 0;
        int ratingsSize = ratings.size();
        vector<int> candies(ratings.size(), 1); // (size_t n, const T& value = T()) - every kid gets one candy. 

        // Intuition: what makes more sense, for loop range based, for each, using iterators...? - 
        // I think we can use just a normal range based here, and we'll need to have some checks for i = 0 and i = ratingsSize - 1?
        
        // So after working on the intuitive solution, I'm realizing, we need to traverse backwards as well. 
        // I worked that out after giving myself a test case that decrements: [4,3,2,1]. We need to add candy the other way, too
        
        // Left to right comparisons
        for (int i = 1; i < ratingsSize; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                // current child has higher rating than the previous child, thus they should get one more candy than the previous
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left comparisons
        for (int i = ratingsSize - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                if (candies[i] <= candies[i + 1]) {
                    // Current child has higher rating than the next child, and our candies are less than or equal to their candy, thus we need more candy for this child
                    candies[i] = candies[i + 1] + 1;
                }
            }
        }

        // This is just for cleaner and more understandable method of loading results
        for (int numOfCandy : candies) {
            result += numOfCandy;
        }

        return result;
    }
};