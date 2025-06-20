class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int idx,
                   vector<int>& curr, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr);  // valid combination
            return;
        }
        if (target < 0) return;

        for (int i = idx; i < candidates.size(); i++) {
            // Skip duplicates at the same level
            if (i > idx && candidates[i] == candidates[i-1]) continue;

            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i+1, curr, res); 
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());  // sort for duplicate removal
        backtrack(candidates, target, 0, curr, res);
        return res;
    }
};
