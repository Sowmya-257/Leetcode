#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev1 = 0, prev2 = 0; // prev1 = dp[i-1], prev2 = dp[i-2]

        for (int i = start; i <= end; i++) {
            int pick = nums[i] + prev2;
            int skip = prev1;
            int curr = max(pick, skip);

            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0]; // only one house
        if (n == 2) return max(nums[0], nums[1]); // pick max of two

        // Case 1: exclude last house
        int case1 = robLinear(nums, 0, n-2);
        // Case 2: exclude first house
        int case2 = robLinear(nums, 1, n-1);

        return max(case1, case2);
    }
};
