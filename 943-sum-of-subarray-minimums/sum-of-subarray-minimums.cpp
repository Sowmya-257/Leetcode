class Solution {
public:
   int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<pair<int, int>> st1, st2;
    long long mod = 1e9 + 7;

    // Step 1. Compute left counts (Previous Less Element)
    for(int i = 0; i < n; i++) {
        int count = 1;
        while(!st1.empty() && st1.top().first > arr[i]) {
            count += st1.top().second;
            st1.pop();
        }
        left[i] = count;
        st1.push({arr[i], count});
    }

    // Step 2. Compute right counts (Next Less or Equal Element)
    for(int i = n - 1; i >= 0; i--) {
        int count = 1;
        while(!st2.empty() && st2.top().first >= arr[i]) {
            count += st2.top().second;
            st2.pop();
        }
        right[i] = count;
        st2.push({arr[i], count});
    }

    // Step 3. Compute total sum
    long long res = 0;
    for(int i = 0; i < n; i++) {
        res = (res + (long long)arr[i] * left[i] * right[i]) % mod;
    }

    return res;
}

};