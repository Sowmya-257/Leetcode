class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    void backtrack(int start, string& s, vector<string>& path, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));  // ✅ Choose
                backtrack(end + 1, s, path, res);                  // \U0001f50e Recurse
                path.pop_back();                                   // \U0001f519 Backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(0, s, path, res);
        return res;
    }
};
