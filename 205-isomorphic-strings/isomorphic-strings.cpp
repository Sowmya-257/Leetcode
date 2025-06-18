class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for (int i = 0; i < s.size(); i++) {
            char chS = s[i];
            char chT = t[i];

            // Check s → t mapping
            if (mapST.count(chS)) {
                if (mapST[chS] != chT) return false;
            } else {
                mapST[chS] = chT;
            }

            // Check t → s mapping
            if (mapTS.count(chT)) {
                if (mapTS[chT] != chS) return false;
            } else {
                mapTS[chT] = chS;
            }
        }

        return true;
    }
};
