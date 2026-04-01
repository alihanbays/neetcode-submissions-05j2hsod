class Solution {
public:
    int ROW, COLS;

    void dfs(vector<vector<int>>& heights, int r, int c, int height, vector<vector<bool>>& boolmap) {
        if (r < 0 || c < 0 || r >= ROW || c >= COLS || boolmap[r][c] == true || height > heights[r][c]) return;

        boolmap[r][c] = true;

        // visit neighbors
        dfs(heights, r + 1, c, heights[r][c], boolmap);
        dfs(heights, r - 1, c, heights[r][c], boolmap);
        dfs(heights, r, c + 1, heights[r][c], boolmap);
        dfs(heights, r, c - 1, heights[r][c], boolmap);

        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROW = heights.size();
        COLS = heights[0].size();
        vector<vector<bool>> pacific(ROW, vector<bool>(COLS, false));
        vector<vector<bool>> atlantic(ROW, vector<bool>(COLS, false));
        vector<vector<int>> result;

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COLS; c++) {
                if (r == 0 || c == 0) dfs(heights, r, c, 0, pacific);
                if (r == ROW - 1 || c == COLS - 1) dfs(heights, r, c, 0, atlantic);
            }
        }

        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COLS; c++) {
                if (atlantic[r][c] == true && pacific[r][c] == true) result.push_back({r,c});
            }
        }
        
        return result;
    }
};
