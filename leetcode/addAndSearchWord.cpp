#include <utility>
#include <queue>
#include <iostream>

using namespace std;

struct TrieNode {  
    TrieNode* children[26];
    bool word;
    char c;
    TrieNode(char ch) : c(ch), word(false), children() {}
};
typedef pair<TrieNode*, int> QNode;
class WordDictionary {
private:
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode(0);
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0; i < word.length(); i++) {
            int next_idx = word[i] - 'a';
            if(cur->children[next_idx] == NULL) {
                cur->children[next_idx] = new TrieNode(word[i]);
            }
            cur = cur->children[next_idx];
        }
        cur->word = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        queue<QNode> q;
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            QNode u = q.front();
            q.pop();
            if(u.second == word.length()) {
                if(u.first->word) {
                    return true;
                }
                continue;
            }
            char next_char = word[u.second];
            if(next_char == '.') {
                for(int i = 0; i < 26; i++) {
                    if(u.first->children[i] != NULL) {
                        q.push(make_pair(u.first->children[i], u.second + 1));
                    }
                }
            } else {
                if(u.first->children[next_char - 'a'] != NULL) {
                    q.push(make_pair(u.first->children[next_char - 'a'], u.second + 1));
                }
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
  WordDictionary* obj = new WordDictionary();
  obj->addWord("bad");
  obj->addWord("dad");
  obj->addWord("mad");
  cout << obj->search("pad") << endl;
  cout << obj->search("bad") << endl;
  cout << obj->search(".ad") << endl;
  cout << obj->search("b..") << endl;
  return 0;
}
