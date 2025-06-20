class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long num = 0;
        int sign = 1;
        bool signSet = false;  // track if sign has been set
        bool numStarted = false;  // track if number has started

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (numStarted || signSet) break;  // space after num or sign => stop
                continue;
            }

            if (s[i] == '-') {
                if (numStarted || signSet) break;  // invalid '-' position
                sign = -1;
                signSet = true;
                continue;
            }

            if (s[i] == '+') {
                if (numStarted || signSet) break;  // invalid '+' position
                sign = 1;
                signSet = true;
                continue;
            }

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                numStarted = true;

                if (sign == 1 && num > INT_MAX) return INT_MAX;
                if (sign == -1 && -num < INT_MIN) return INT_MIN;
                continue;
            }

            // if non-digit, non-space, non-sign after num starts => stop
            break;
        }

        return (int)(sign * num);
    }
};
