class TrieNode {
private:
    bool word;
    map<char, TrieNode*> dict;
public:
    // Initialize your data structure here.
    TrieNode() {
        word = false;
    }
    bool setWord() {
        word = true;
    }
    bool isWord() {
        return word;
    }
    TrieNode* traverse(char c) {
        if(dict.count(c))
            return dict[c];
        return dict[c] = new TrieNode();
    }
    bool contains(char ch) {
        return dict.count(ch);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.length(); i++) {
            curr = curr->traverse(word[i]);
        }
        curr->setWord();
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.length(); i++) {
            if(!curr->contains(word[i]))
                return false;
            curr = curr->traverse(word[i]);
        }
        return curr->isWord();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(!curr->contains(prefix[i]))
                return false;
            curr = curr->traverse(prefix[i]);
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
