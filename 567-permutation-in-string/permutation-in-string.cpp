class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        if (len1 > len2) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // Count frequency for s1 and first window of s2
        for (int i = 0; i < len1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        // Slide the window
        for (int i = len1; i < len2; i++) {
            if (freq1 == freq2) return true;

            // Slide window: remove old char, add new char
            freq2[s2[i - len1] - 'a']--;  // Remove from left
            freq2[s2[i] - 'a']++;         // Add on right
        }

        // Check final window
        return freq1 == freq2;
    }
};
