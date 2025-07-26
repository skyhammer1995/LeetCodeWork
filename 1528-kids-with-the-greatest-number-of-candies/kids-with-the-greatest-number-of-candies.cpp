class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result(candies.size()); // I'm not sure if it's a good idea to preallocate size and replace in the for loop. It is easier to just do something like push_back()
        // find max, compare if candies[i] + extraCandies >= max, true if yes, false if no
        vector<int>::iterator maxIt = std::max_element(candies.begin(), candies.end());

        for (int i = 0; i < candies.size(); ++i) {
            result[i] = (candies[i] + extraCandies >= *maxIt);
        }

        return result;
    }
};