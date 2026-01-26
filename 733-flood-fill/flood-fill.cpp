class Solution {
public:
    int m, n;
    int oldColor, newColor;

    void dfs(int r, int c, vector<vector<int>>& image) {
        // boundary check
        if (r < 0 || c < 0 || r >= m || c >= n)
            return;

        // color mismatch check
        if (image[r][c] != oldColor)
            return;

        // change color
        image[r][c] = newColor;

        // 4-direction DFS
        dfs(r + 1, c, image);
        dfs(r - 1, c, image);
        dfs(r, c + 1, image);
        dfs(r, c - 1, image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {
        m = image.size();
        n = image[0].size();
        oldColor = image[sr][sc];
        newColor = color;

        if (oldColor == newColor)
            return image;

        dfs(sr, sc, image);
        return image;
    }
};
