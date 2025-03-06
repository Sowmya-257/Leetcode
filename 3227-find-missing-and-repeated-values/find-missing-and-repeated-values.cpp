class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int max = n * n;
        int rep = -1, mis = -1;

        // Use a vector instead of a raw array
        vector<int> freq(max + 1, 0);

        // Count the frequency of each number in the grid
        for (const auto& row : grid) {
            for (int num : row) {
                freq[num]++;
            }
        }
 
        for(int i=1;i<=max;i++){
            if(freq[i]== 2){
                rep=i;
            }           
        }
        for(int i=1;i<=max;i++){
            if(freq[i]==0){
                mis=i;
            }         
        }
        return {rep,mis};
    }
};