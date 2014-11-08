#include <iostream>
#include <queue>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

bool doublespecification = false;

struct Node {
  Node() {
    filled = false;
    left = NULL;
    right = NULL;
  };
  int n;
  Node* left;
  Node* right;
  bool filled;
};

bool checkTree(Node* root) {
  if(!root->filled || doublespecification)
    return false;
  bool result = true;
  if(root->left != NULL)
    result  = result && checkTree(root->left);
  if(root->right != NULL)
    result = result && checkTree(root->right);
  return result;
}

void printTree(Node* root) {
  queue<Node *> q;
  q.push(root);
  vector<int> result;
  while(!q.empty()) {
    Node* next = q.front();
    q.pop();
    result.push_back(next->n);
    if(next->left != NULL)
      q.push(next->left);
    if(next->right != NULL)
      q.push(next->right);
  }
  for(int i= 0; i < result.size(); i++) {
    if(i != result.size() - 1)
      cout << result[i] << " ";
    else
      cout << result[i] << endl;
  }
}

void deleteTree(Node* node) {
  if(node->left != NULL)
    deleteTree(node->left);
  if(node->right != NULL)
    deleteTree(node->right);
  delete node;
}

int main() {
  string line;
  Node* root = new Node;
  while(cin >> line) {
    if(line == "()") {
      if(checkTree(root)) {
	printTree(root);
      } else {
	cout << "not complete" << endl;
      }
      deleteTree(root);
      root = new Node;
      doublespecification = false;
    } else {
      istringstream iss(line.c_str());
      string firstHalf, secondHalf;
      getline(iss, firstHalf, ',');
      getline(iss, secondHalf);
      int number = atoi(firstHalf.substr(1).c_str());
      Node* insertNode = root;
      for(int i= 0; i < secondHalf.length() - 1; i++) {
	if(secondHalf[i] == 'L') {
	  if(insertNode->left == NULL) {
	    insertNode->left = new Node;
	  }
	  insertNode = insertNode->left;
	}
	if(secondHalf[i] == 'R') {
	  if(insertNode->right == NULL) {
	    insertNode->right = new Node;
	  }
	  insertNode = insertNode->right;
	}
      }
      if(insertNode->filled)
	doublespecification = true;
      insertNode->filled = true;
      insertNode->n = number;
    }
  }
}
