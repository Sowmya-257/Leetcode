class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int n1= s.size();
        int n2= t.size();

        if(n1 != n2) return false;

        for(int i=0 ; i<n1 ;i++){
            if(s[i] != t[i]) return false;
        }
       return true;
    }
};





















//  if (s.length() != t.length()) return false;

//         int count[26] = {0};

//         for (int i = 0; i < s.length(); i++) {
//             count[s[i] - 'a']++;
//             count[t[i] - 'a']--;
//         }

//         for (int i = 0; i < 26; i++) {
//             if (count[i] != 0) return false;
//         }

//         return true;