class Solution {
public:
    bool dfs(int r, int c, vector<vector<char>>& board, string word, string substr) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] == '#') return false;

        char temp = board[r][c];
        substr += temp;

        if (substr == word) return true;

        board[r][c] = '#';
        
        bool right = dfs(r + 1, c, board, word, substr);
        bool left = dfs(r - 1, c, board, word, substr);
        bool up = dfs(r, c + 1, board, word, substr);
        bool down = dfs(r, c - 1, board, word, substr);
        
        board[r][c] = temp;
        return (right || left || up || down);
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (dfs(r, c, board, word, "")) {
                    return true;
                }
            }
        }

        return false;
    }
};
