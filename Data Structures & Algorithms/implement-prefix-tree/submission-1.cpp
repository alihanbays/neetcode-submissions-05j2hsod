class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool word = false;
};
class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char& ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char& ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch];
        }
        return curr->word;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char& ch : prefix) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch];
        }
        return true;
    }
};
