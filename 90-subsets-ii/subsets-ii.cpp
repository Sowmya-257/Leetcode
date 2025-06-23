class Solution {
public:
    void back(vector<int>& nums, int idx, vector<int>& curr, vector<vector<int>>& res) {
        res.push_back(curr);  // Line 1

        for (int i = idx; i < nums.size(); ++i) {  // Line 2
            if (i > idx && nums[i] == nums[i - 1]) continue;  // Line 3

            curr.push_back(nums[i]);  // Line 4
            back(nums, i + 1, curr, res);  // Line 5
            curr.pop_back();  // Line 6
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Line 7
        vector<vector<int>> res;  // Line 8
        vector<int> curr;  // Line 9
        back(nums, 0, curr, res);  // Line 10
        return res;  // Line 11
    }
};
