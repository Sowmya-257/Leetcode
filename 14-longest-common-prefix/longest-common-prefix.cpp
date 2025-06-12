class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; // Handle edge case of an empty array
        
        string prefix = strs[0]; // Initialize prefix as the first string
        
        for (int i = 1; i < strs.size(); i++) {
            // Reduce the prefix until it matches the start of strs[i]
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1); // Remove the last character
                if (prefix.empty()) return ""; // If no common prefix exists
            }
        }
        return prefix;
    }
};
