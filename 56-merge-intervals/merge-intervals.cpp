class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        
        // Step 1: Sort based on starting time
        sort(intervals.begin(), intervals.end());
        
        // Step 2: Start with the first interval
        merged.push_back(intervals[0]);
        
        // Step 3: Traverse and merge if needed
        for (int i = 1; i < intervals.size(); i++) {
            vector<int>& last = merged.back();
            
            if (intervals[i][0] <= last[1]) {
                // Merge: update the end time
                last[1] = max(last[1], intervals[i][1]);
            } else {
                // No overlap: add as is
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};
