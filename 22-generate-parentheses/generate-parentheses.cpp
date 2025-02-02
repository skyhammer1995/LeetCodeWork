class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        function<void(int, int, string)> depthFirstSearch = [&](int openCount, int closeCount, string current) {
            if (openCount > n || closeCount > n || openCount < closeCount) {
                return;
            }

            if (openCount == n && closeCount == n) {
                result.push_back(current);
                return;
            }

            depthFirstSearch(openCount + 1, closeCount, current + "(");
            depthFirstSearch(openCount, closeCount + 1, current + ")");
        };

        depthFirstSearch(0, 0, "");

        return result;
    }
};