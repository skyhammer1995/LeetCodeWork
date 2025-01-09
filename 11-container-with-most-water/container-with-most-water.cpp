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


        // for (int left = 0; left < height.size(); ++left) {
        //     int right = height.size() - 1;
        //     int currentMaxArea = 0;
        //     while (left < right) {
        //         int minHeight = std::min(height[left], height[right]);
        //         int base = right - left;
        //         currentMaxArea = base*minHeight;
        //         if (currentMaxArea > maxArea) {
        //             maxArea = currentMaxArea;
        //         }
        //         if ()
        //         --right;
        //     }
        // }

        return maxArea;
    }
};