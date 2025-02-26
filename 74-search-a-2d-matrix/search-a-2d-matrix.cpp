class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }

        for (std::vector<std::vector<int>>::iterator rows = matrix.begin(); rows != matrix.end();) {
            if (rows->empty() || rows->back() < target ) {
                // target could be in next row, iterate to the next row
                ++rows;
            } else if (rows->front() > target) {
                // target was not in previous row, and cannot be found; target is not in the matrix
                return false;
            } else if (rows->front() <= target && target <= rows->back()) {
                // target should be within this row, return false if we don't find it (we could also break out for same result, but I'd rather be explicit for clarity)
                if (std::find(rows->begin(), rows->end(), target) != rows->end()) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        
        // cases where we couldn't find anything within the matrix target was beyond maximum
        return false;
    }
};