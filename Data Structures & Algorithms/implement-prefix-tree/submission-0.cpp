class PrefixNode {
public:
    unordered_map<char, PrefixNode*> children;
    bool word;
    PrefixNode() {}
};
class PrefixTree {
public:
    PrefixNode* root;

    PrefixTree() {
        root = new PrefixNode();
    }
    
    void insert(string word) {
        PrefixNode* curr = root;

        for (char& ch : word) {
            auto it = curr->children.find(ch);

            if (it == curr->children.end()) { // if its in the children
                curr->children[ch] = new PrefixNode();
            }
            curr = curr->children[ch];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        PrefixNode* curr = root;

        for (char& ch : word) {
            auto it = curr->children.find(ch);

            if (it == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch];
        }
        return curr->word;
    }
    
    bool startsWith(string prefix) {
        PrefixNode* curr = root;

        for (char& ch : prefix) {
            auto it = curr->children.find(ch);

            if (it == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch];
        }
        return true;
    }
};
