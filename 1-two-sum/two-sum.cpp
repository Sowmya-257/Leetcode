class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int> seen; 
       for (int i = 0; i < nums.size(); i++) {
            int remain = target - nums[i];
            if (seen.count(remain)) {
                return {seen[remain], i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};