class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int i = 0; // read pointer
        int index = 0; // write pointer

        while (i < n) {
            char current = chars[i];
            int count = 0;

            // Count the number of occurrences of the current char
            while (i < n && chars[i] == current) {
                i++;
                count++;
            }

            // Write the character
            chars[index] = current;
            index++;
            // Write the count (if more than 1)
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[index] = c;
                    index++;
                }
            }
        }

        return index;
    }
};
