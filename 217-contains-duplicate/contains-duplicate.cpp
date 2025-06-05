class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n= nums.size();
        unordered_map<int,int> frequency;

        for(int num : nums){
            frequency[num]++;
            if(frequency[num] >1){
                return true;
                break;
            }
        }
        return false;
    }
};