class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();

        if(n==0) return 0;

        for(int i=n-2; i>=0 ;i--){
            for(int j=0; j<n ;j++){
                int down = matrix[i+1][j];
                int left = (j > 0) ? matrix[i+1][j-1] : INT_MAX;
                int right = (j < n-1) ? matrix[i+1][j+1] : INT_MAX;

                matrix[i][j] += min({down,left,right});
            }
        }
        return *min_element(matrix[0].begin(), matrix[0].end());
    }
};