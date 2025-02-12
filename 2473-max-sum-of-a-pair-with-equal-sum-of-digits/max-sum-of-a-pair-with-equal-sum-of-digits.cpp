class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, pair<int, int>> digitSumMap;
        int maxSum = -1;

        for (int num : nums) {
            int digitSum = getDigitSum(num);

            // Retrieve the two largest numbers with the same digit sum
            auto &[largest, secondLargest] = digitSumMap[digitSum];

            if (num > largest) {
                // Update both largest and second largest
                secondLargest = largest;
                largest = num;
            } else if (num > secondLargest) {
                // Update only second largest
                secondLargest = num;
            }

            // If we have two numbers, update maxSum
            if (secondLargest != 0) {
                maxSum = max(maxSum, largest + secondLargest);
            }
        }

        return maxSum;
    }

    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
