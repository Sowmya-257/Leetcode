class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If not possible to split
        if ((totalSum + target) % 2 != 0 || totalSum < abs(target)) 
            return 0;

        int P = (totalSum + target) / 2;

        // dp[t] = number of ways to make sum = t
        vector<int> dp(P + 1, 0);
        dp[0] = 1;  // one way to make 0 (pick nothing)

        for (int num : nums) {
            for (int t = P; t >= num; t--) {
                dp[t] += dp[t - num];
            }
        }

        return dp[P];
    }
};