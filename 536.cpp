#include <iostream>
#include <map>

using namespace std;

struct Node {
  Node(char val) : c(val) {
    left = NULL;
    right = NULL;
  };
  char c;
  Node* left;
  Node* right;
};

map<char, int> indexMap;

Node* buildTree(string preord) {
  if(preord.length() == 1) {
    Node* result = new Node(preord[0]);
    return result;
  } else {
    int compare = indexMap[preord[0]];
    int llength = 0;
    for(int i= 1; i < preord.length(); i++) {
      if(indexMap[preord[i]] > compare) {
	break;
      } else {
	llength++;
      }
    }
    string leftStr = preord.substr(1, llength);
    string rightStr = preord.substr(1 + llength);

    Node* result = new Node(preord[0]);
    if(leftStr.length() != 0)
      result->left = buildTree(leftStr);
    if(rightStr.length() != 0)
      result->right = buildTree(rightStr);
    return result;
  }
}

void postOrderPrint(Node* node) {
  if(node->left != NULL)
    postOrderPrint(node->left);
  if(node->right != NULL)
    postOrderPrint(node->right);
  cout << node->c;
}

void deleteTree(Node* node) {
  if(node->left != NULL)
    deleteTree(node->left);
  if(node->right != NULL)
    deleteTree(node->right);
  delete node;
}

int main() {
 string preord, inord;
  while(cin >> preord >> inord) {
    indexMap.clear();
    for(int i= 0; i < inord.length(); i++) {
      indexMap[inord[i]] = i;
    }
    Node* root = buildTree(preord);
    postOrderPrint(root);
    cout << endl;
    deleteTree(root);
  }
  return 0;
}
