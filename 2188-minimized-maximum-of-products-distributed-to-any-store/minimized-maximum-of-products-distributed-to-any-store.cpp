class Solution {
public:
    // Checks if we can distribute quantities to n stores with maxProducts per store
    bool isPossible(int maxProducts, int n, vector<int>& quantities) {
        int storesNeeded = 0;
        for (int q : quantities) {
            // Compute stores needed for each product type
            storesNeeded += (q + maxProducts - 1) / maxProducts; // ceil(q / maxProducts)
        }
        return storesNeeded <= n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isPossible(mid, n, quantities)) {
                result = mid;     // valid, try to minimize
                right = mid - 1;
            } else {
                left = mid + 1;   // too small, increase
            }
        }

        return result;
    }
};
