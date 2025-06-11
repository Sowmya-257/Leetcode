class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int curr_max = nums[0];
        int curr_min = nums[0];
        int max_product = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            int temp = curr_max;

            // Calculate new max and min ending at i
            curr_max = max({nums[i], curr_max * nums[i], curr_min * nums[i]});
            curr_min = min({nums[i], temp * nums[i], curr_min * nums[i]});

            max_product = max(max_product, curr_max);
        }

        return max_product;
    }
};
