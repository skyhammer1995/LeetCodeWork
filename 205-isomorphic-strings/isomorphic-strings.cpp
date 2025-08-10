// after one submission, I'm realizing we're checking one direction. We need to
// check both.

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        size_t sizeS = s.size();
        size_t sizeT = t.size();
        if (sizeS != sizeT) {
            return false;
        }

        std::unordered_map<char, char> isoMap_s_to_t;
        std::unordered_map<char, char> isoMap_t_to_s;

        for (int i = 0; i < sizeS; ++i) {
            int cs = s[i];
            int ct = t[i];

            // check from s -> t
            if (isoMap_s_to_t.count(cs) && isoMap_s_to_t[cs] != ct) {
                // if cs is present as a key, and its paired element does not match the current T letter    
                return false;
            }

            // check from t -> s
            if (isoMap_t_to_s.count(ct) && isoMap_t_to_s[ct] != cs) {
                // if ct is present as a key, and its paired element does not match the current S letter
                return false;
            }

            // add to both maps
            isoMap_s_to_t[cs] = ct;
            isoMap_t_to_s[ct] = cs;
        }

        return true;
    }
};