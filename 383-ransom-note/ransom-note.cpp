class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // we can only use each letter per occurrence
        if (ransomNote.size() > magazine.size()) {
            return false;
        }
        
        std::unordered_map<char, int> magazineMap;

        for (int i = 0; i < magazine.size(); ++i) {
            // increment the value for particular keys found.
            ++magazineMap[magazine[i]];
        }

        for (int i = 0; i < ransomNote.size(); ++i) {
            if (magazineMap[ransomNote[i]] != 0) {
                --magazineMap[ransomNote[i]];
            } else {
                // we have exhausted the number of available letters, can't do it
                return false;
            }
        }

        return true;
    }
};