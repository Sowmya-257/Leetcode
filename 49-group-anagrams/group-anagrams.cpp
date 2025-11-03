class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map< string , vector<string>> anagramMap;

        for(auto &s : strs){
            string key = s;
            sort(key.begin(), key.end());
            anagramMap[key].push_back(s);
        }

        vector<vector<string>> res;

        for(auto &entry : anagramMap){
            res.push_back(entry.second);
        }

        return res;
    }
};



















