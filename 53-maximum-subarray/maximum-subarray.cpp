class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0];
        int maxSum = nums[0];
        int n=nums.size();

        if(n==1){
            return nums[0];
        }

        for(int i=1; i< n;i++){
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};