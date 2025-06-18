class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();

        int r= n-1;

        while(r>=0){
            if ((num[r] - '0') % 2 != 0) {
                return num.substr(0, r + 1);
            }
              r--;
        }
        return "";
    }
};