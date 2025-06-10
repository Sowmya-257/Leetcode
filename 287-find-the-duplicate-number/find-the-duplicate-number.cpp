class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       unordered_set<int> s;
int n = nums.size() - 1;
int b;

for (int i = 0; i <= n; i++) {
    if (s.find(nums[i]) != s.end()) {
        b = nums[i];
    }
    s.insert(nums[i]);
}
return b;

    }
};






