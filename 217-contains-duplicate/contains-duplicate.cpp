class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(m.find(nums[i]) != m.end()){
                return true;
            }
            m[nums[i]]++;
        }
        return false;
    }
};





















// sort(nums.begin(),nums.end());
//         for(int i=0; i<nums.size()-1;i++){
//             if(nums[i]==nums[i+1]) {
//             return true;
//             break;
//             };
//         }
//         return false;