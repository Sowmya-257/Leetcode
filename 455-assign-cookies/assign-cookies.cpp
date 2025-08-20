class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  // sort greed
        sort(s.begin(), s.end());  // sort cookies

        int i = 0; // pointer for children
        int j = 0; // pointer for cookies

        // try to satisfy children in order
        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                // cookie satisfies child
                i++; // move to next child
            }
            // whether satisfied or not, move to next cookie
            j++;
        }
        return i;
    }
};