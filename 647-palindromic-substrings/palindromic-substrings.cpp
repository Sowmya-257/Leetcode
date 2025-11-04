#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // helper function outside countSubstrings
    int expand(string &st, int left, int right) {
        int cnt = 0;
        int n = st.size();

        while (left >= 0 && right < n && st[left] == st[right]) {
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Odd-length palindromes
            count += expand(s, i, i);

            // Even-length palindromes
            count += expand(s, i, i + 1);
        }

        return count;
    }
};
