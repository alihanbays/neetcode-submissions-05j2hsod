class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool word = false;
};

class Trie {
public:
    TrieNode* head;
    Trie() {
        head = new TrieNode();
    }
};

class Solution {  
public:
    void addWords(TrieNode* head, string& word) {
        TrieNode* curr = head;
        for (char& ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->word = true;
    }

    void dfs(vector<vector<char>>& board, vector<string>& res, string word, TrieNode* curr, int r, int c) {
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || curr->children.find(board[r][c]) == curr->children.end()) {
            return;
        }

        char tmp = board[r][c];
        board[r][c] = '#';
        word += tmp;
        curr = curr->children[tmp];

        if (curr->word && find(res.begin(), res.end(), word) == res.end()) {
            res.push_back(word);
        }

        dfs(board, res, word, curr, r + 1, c);
        dfs(board, res, word, curr, r - 1, c);
        dfs(board, res, word, curr, r, c + 1);
        dfs(board, res, word, curr, r, c - 1);

        board[r][c] = tmp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie tree;
        for (string& word : words) {
            addWords(tree.head, word);
        }

        int ROW = board.size();
        int COL = board[0].size();
        vector<string> res;
        
        for (int r = 0; r < ROW; r++) {
            for (int c = 0; c < COL; c++) {
                dfs(board, res, "", tree.head, r, c);
            }
        }

        return res;
    }
};
