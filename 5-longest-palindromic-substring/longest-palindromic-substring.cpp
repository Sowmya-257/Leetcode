#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Helper function to expand from the center
    string expand(string &s, int left, int right) {
        int n = s.size();
        while (left >= 0 && right < n && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        string longest = "";

        for (int i = 0; i < n; i++) {
            string odd = expand(s, i, i);
            string even = expand(s, i, i + 1);
            if (odd.size() > longest.size()) longest = odd;
            if (even.size() > longest.size()) longest = even;
        }

        return longest;
    }
};
