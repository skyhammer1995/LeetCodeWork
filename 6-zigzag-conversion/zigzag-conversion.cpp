class Solution {
public:
    string convert(string s, int numRows) {
        // ez
        if (numRows == 1) {
            return s;
        }
        // I'm thinking that we can just add the letter from current element to certain positions. Need to think out math.
        // it should be row, append, row, append, etc.

        vector<std::string> rows(numRows);
        int row = 0;
        int step = 1;

        for (char c : s) {
            rows[row] += c;
            if (row == 0) {
                step = 1;
            }

            if (row == numRows - 1) {
                step = -1;
            }

            row += step;
        }

        string result;
        for (string row : rows) {
            result += row;
        }
        return result;
    }
};