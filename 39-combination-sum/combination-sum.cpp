class Solution {
public:
    void backtrack(vector<int>& candidates, int target, int index, vector<int>& curr, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(curr);  // found valid combination
            return;
        }
        if (target < 0) return;      // sum exceeded target

        for (int i = index; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, curr, result);  // allow reuse
            curr.pop_back();  // backtrack
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(candidates, target, 0, curr, result);
        return result;
    }
};
