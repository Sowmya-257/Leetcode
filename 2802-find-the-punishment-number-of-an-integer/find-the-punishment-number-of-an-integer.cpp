class Solution {
public:
    int punishmentNumber(int n) {
        int count = 0;
        
        for (int i = 1; i <= n; i++) {
            int square = i * i;
            string s = to_string(square);
            if (canPartition(s, 0, i, 0)) {  // Corrected condition
                count += square;
            }
        }
        
        return count;
    }

private:
    bool canPartition(const string &s, int index, int target, int currentSum) {
        if (index == s.length()) {
            return currentSum == target;  // ✅ If we reached the end and sum == target, return true
        }
        
        int num = 0;
        for (int i = index; i < s.length(); i++) {
            num = num * 10 + (s[i] - '0');  // Form number from substring
            
            if (num + currentSum > target) break; // ❌ Stop if sum exceeds target
            
            // \U0001f504 Recursively check next part of string
            if (canPartition(s, i + 1, target, currentSum + num)) {
                return true;  // ✅ If a valid partition is found, return true
            }
        }
        return false;  // ❌ If no valid partition is found, return false
    }
};
