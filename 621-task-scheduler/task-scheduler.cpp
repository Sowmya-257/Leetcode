class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
    for (char task : tasks) {
        freq[task]++;
    }

    // Step 2: Find the task(s) with maximum frequency
    int maxFreq = 0;
    for (auto it : freq) {
        maxFreq = max(maxFreq, it.second);
    }

    // Step 3: Count how many tasks have this max frequency
    int maxCount = 0;
    for (auto it : freq) {
        if (it.second == maxFreq) {
            maxCount++;
        }
    }

    // Step 4: Apply the formula
    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int emptySlots = partCount * partLength + maxCount;

    // Step 5: Return the max between total tasks and the calculated emptySlots
    return max((int)tasks.size(), emptySlots);
    }
};