class Solution {
public:

    // Static comparator function
    static bool compare(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        unordered_map<char, int> freq;

        // Count frequency
        for (char c : s) {
            freq[c]++;
        }

        // Put into vector
        vector<pair<char, int>> freqVec;
        for (auto it : freq) {
            freqVec.push_back(it);
        }

        // Sort using our static comparator
        sort(freqVec.begin(), freqVec.end(), compare);

        // Build result
        string result = "";
        for (auto it : freqVec) {
            result += string(it.second, it.first);
        }

        return result;
    }
};
