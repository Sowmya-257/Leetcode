class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result; // Acts like a stack
        int partLen = part.length();

        for (char ch : s) {
            result.push_back(ch); // Append each character

            // Check if the last `partLen` characters match `part`
            if (result.size() >= partLen && result.substr(result.size() - partLen) == part) {
                result.erase(result.size() - partLen); // Remove the substring
            }
        }
        return result;
    }
};