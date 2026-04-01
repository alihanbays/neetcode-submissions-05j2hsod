class TrieNode {
public:
    unordered_map<char, TrieNode*> um;
    bool word = false;
};

class WordDictionary {
public:
    TrieNode* head;
    WordDictionary() {
        head = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = head;

        for (char& ch : word) {
            if (curr->um.find(ch) == curr->um.end()) {
                curr->um[ch] = new TrieNode();
            }
            curr = curr->um[ch];
        }
        curr->word = true;
    }
    
    bool dfs(TrieNode* curr, int index, string word) {
        for (int i = index; i < word.length(); i++) {
            if (word[i] == '.') {
                for (auto it = curr->um.begin(); it != curr->um.end(); ++it) {
                    if (dfs(it->second, i + 1, word)) {
                        return true;
                    }
                }
                return false;
            } else if (curr->um.find(word[i]) == curr->um.end()) {
                return false;
            } else {
                curr = curr->um[word[i]];

            }
        }
        return curr->word;
    }

    bool search(string word) {
        TrieNode* curr = head;
        int index = 0;
        return dfs(curr, index, word);
    }
};
