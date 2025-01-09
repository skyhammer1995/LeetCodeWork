class Solution {
public:
    int maxArea(vector<int>& height) {
        std::vector<int>::iterator::difference_type maxArea = 0;
        std::vector<int>::iterator left = height.begin();
        std::vector<int>::iterator right = height.end() - 1;

         while (left < right) {
            maxArea = std::max(maxArea, ((right - left) * std::min(*left, *right)));
            std::cout << maxArea << std::endl;
            if (*left > *right) {
                --right;
            } else {
                ++left;
            }
        }

        return maxArea;
    }
};