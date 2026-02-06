class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size() > nums2.size()) 
            return intersection(nums2, nums1);

        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;

        for(int x : nums2) {
            if(s.count(x)) {
                ans.push_back(x);
                s.erase(x);  // ensures uniqueness
            }
        }

        return ans;
    }
};
