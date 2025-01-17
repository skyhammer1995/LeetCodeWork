class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string result{};

        std::sort(strs.begin(), strs.end());

        std::string front = strs.front();
        std::string back = strs.back();
        // iterate for whichever is smallest
        int size = min(front.size(), back.size());

        int i = 0;

        while (i < size && front[i] == back[i]) {
            result += front[i];
            i++;
        }

        return result;
    }
};