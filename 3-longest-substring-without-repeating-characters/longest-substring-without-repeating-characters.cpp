// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         unordered_map<char,int> seen;
//         int start =0;
//         int len=0;
//         for(int i=0;i<s.length();i++ ){
//             char curr= s[i];
//             if(seen.count(curr) && seen[curr] >= start){
//                 start = seen[curr]+1;
//             }
//             seen[curr] = i;
//             len = max(len, i - start + 1);
//         }  
//         return len;
//     }
// };


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>seen;
        int left=0,right=0,maxLength=0;

        while(right<s.size()){
            if(seen.find(s[right])== seen.end()){
                seen.insert(s[right]);
                maxLength = max(maxLength, right-left+1);
                right++;
            }else{
                seen.erase(s[left]);
                left++;
            }
        }
        return maxLength;
    }
};













