#include <bits/stdc++.h>

using namespace std;

struct DoubleListNode {
  int key;
  int val;
  DoubleListNode* left;
  DoubleListNode* right;
  DoubleListNode(int k, int v) : key(k), val(v), left(NULL), right(NULL) {}
};

class LRUCache{
private:
    unordered_map<int, DoubleListNode*> m;
    int size, cap;
    DoubleListNode* head, *tail;
    void removeNode(DoubleListNode* a) {
        a->left->right = a->right;
        a->right->left = a->left;
        m.erase(a->key);
        delete a;
        size--;
    }
    void insertAtEnd(DoubleListNode* a) {
        a->right = tail;
        a->left = tail->left;
        tail->left->right = a;
        tail->left = a;
        m[a->key] = a;
        size++;
    }
public:
    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
        head = new DoubleListNode(-1, -1);
        tail = new DoubleListNode(-1, -1);
        head->right = tail;
        tail->left = head;
    }
    
    int get(int key) {
        if(m.count(key) == 0)
            return -1;
	DoubleListNode* ans = new DoubleListNode(m[key]->key, m[key]->value);
	removeNode(m[key]);
	insertAtEnd(ans);
        return m[key]->val;
    }

    void set(int key, int value) {
        DoubleListNode* ans = new DoubleListNode(key, value);
        if(m.count(key)) {
            removeNode(m[key]);
            insertAtEnd(ans);
        } else {
            insertAtEnd(ans);
            if(size > cap)
                removeNode(head->right);
        }
    }
};

int main() {
  LRUCache cache(2);
  cache.set(2, 1);
  cache.set(1, 1);
  cout << cache.get(2) << endl;
  cache.set(4, 1);
  cout << cache.get(1) << endl;
  cout << cache.get(2) << endl;
  return 0;
}
