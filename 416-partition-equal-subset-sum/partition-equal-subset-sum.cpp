class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false; // Odd sum can't be partitioned equally

        int target = sum / 2;
        int n = nums.size();

        vector<bool> dp(target + 1, false);
        dp[0] = true; // sum 0 is always possible (empty set)

        for (int num : nums) {
            for (int t = target; t >= num; t--) {
                dp[t] = dp[t] || dp[t - num];
            }
        }

        return dp[target];
    }
};