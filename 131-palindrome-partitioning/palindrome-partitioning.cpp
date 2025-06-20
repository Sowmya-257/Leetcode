class Solution {
public:
    bool isPalindrome(const string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }

    void backtrack(string &s, int ind, vector<string> &curr, vector<vector<string>> &res) {
        if (ind == s.size()) {
            res.push_back(curr);  // add one valid partition
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            // if substring s[ind:i] is palindrome, choose it
            if (isPalindrome(s, ind, i)) {
                curr.push_back(s.substr(ind, i - ind + 1));
                backtrack(s, i + 1, curr, res);  // go to next part
                curr.pop_back();                 // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, curr, res);  // start at index 0
        return res;
    }
};
