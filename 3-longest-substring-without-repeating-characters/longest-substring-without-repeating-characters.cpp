class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int n=s.size();
       unordered_map<char,int> m;
       int left=0;
       int maxC=0;

       for(int i=0;i<n;i++){
           if( m.count(s[i]) && m[s[i]] >= left){
                left = m[s[i]]+ 1;
           }

           m[s[i]]= i;
           maxC= max(maxC, i-left+1);
       }

       return maxC;
    }
};

























//  unordered_map<char,int> seen;
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











