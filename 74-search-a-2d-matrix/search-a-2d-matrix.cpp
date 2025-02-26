class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        for (const std::vector<int>& row : matrix) {
            if (target >= row.front() && target <= row.back()) {
                int left = 0;
                int right = row.size() - 1;

                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    if (row[mid] == target) {
                        return true;
                    } else if (row[mid] < target) {
                        left = mid + 1;
                    } else if (row[mid] > target) {
                        right = mid - 1;
                    }
                }
            }
        }
        
        // cases where we couldn't find anything within the matrix target was beyond maximum
        return false;
    }
};