class Trie {
    bool isTerminal;
    Trie* children[26]; // Array to store pointers to child Trie nodes

public:
    Trie() : isTerminal(false) {
        for (int i = 0; i < 26; ++i) children[i] = nullptr; // Initialize all children as nullptr
    }
    
    ~Trie() { // Destructor to free memory
        for (int i = 0; i < 26; ++i)
            if (children[i]) delete children[i];
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new Trie();
            node = node->children[c - 'a'];
        }
        node->isTerminal = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->children[c - 'a'] == nullptr)
                return false;
            node = node->children[c - 'a'];
        }
        return node != nullptr && node->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c : prefix) {
            if (node->children[c - 'a'] == nullptr)
                return false;
            node = node->children[c - 'a'];
        }
        return true; // If we successfully find the node representing the last char of prefix
    }
};
