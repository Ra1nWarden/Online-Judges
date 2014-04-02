#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <climits>

using namespace std;

struct node {
  int value;
  int marbles;
  node* parent;
  node(int val, int marbs): value(val),marbles(marbs){
    parent = NULL;
  };
};

struct config {
  vector<node*>* marbleNode;
  vector<node*>* emptyNode;
  config(vector<node*>* marb, vector<node*>* empty):marbleNode(marb),emptyNode(empty) {};
  string generateCode() {
    vector<int> marbleNo;
    vector<int> emptyNo;
    for(int i = 0; i < marbleNode->size(); i++)
      marbleNo.push_back(marbleNode->at(i)->value);
    for(int i = 0; i < emptyNode->size(); i++)
      emptyNo.push_back(emptyNode->at(i)->value);
    sort(marbleNo.begin(), marbleNo.end());
    sort(emptyNo.begin(), emptyNo.end());
    ostringstream oss;
    for(int i = 0; i < marbleNo.size(); i++)
      oss << marbleNo[i];
    for(int i = 0; i < emptyNo.size(); i++)
      oss << emptyNo[i];
    string result = oss.str();
    return result;
  };
};

int findDist(node* a, node* b) {
  int result = 0;
  vector<node*> parentsa;
  vector<node*> parentsb;
  while(a != NULL) {
    parentsa.push_back(a);
    a = a->parent;
  }
  while(b != NULL) {
    parentsb.push_back(b);
    b = b->parent;
  }
  for(int i = 0; i < parentsa.size(); i++) {
    node* aparent = parentsa[i];
    for(int j = 0; j < parentsb.size(); j++) {
      node* bparent = parentsb[j];
      if(aparent == bparent) {
	return (i+j);
      }
    }
  }
  return result;
}

int findMin(config& currentConfig, map<string, int>& myMap) {
  int nodeleft = currentConfig.emptyNode->size();
  if(nodeleft == 0)
    return 0;
  else if(nodeleft == 1) {
    node* marbnode = currentConfig.marbleNode->at(0);
    node* emptnode = currentConfig.emptyNode->at(0);
    int result = findDist(marbnode, emptnode);
    myMap[currentConfig.generateCode()] = result;
    return result;
  }
  else {
    if(myMap.count(currentConfig.generateCode()) != 0) {
      return myMap[currentConfig.generateCode()];
    }
    int minresult = INT_MAX;
    node* marbnode = currentConfig.marbleNode->at(0);
    for(int i = 0; i < currentConfig.emptyNode->size(); i++) {
      int currentresult = 0;
      node* moveNode = currentConfig.emptyNode->at(i);
      vector<node*>* nextEmpty = new vector<node*>(*currentConfig.emptyNode);
      nextEmpty->erase(find(nextEmpty->begin(), nextEmpty->end(), moveNode));
      vector<node*>* nextMarble = new vector<node*>(*currentConfig.marbleNode);
      nextMarble->erase(find(nextMarble->begin(), nextMarble->end(), marbnode));
      config nextConfig(nextMarble, nextEmpty);
      if(myMap.count(nextConfig.generateCode()) != 0) {
	currentresult = myMap[nextConfig.generateCode()];
      }
      else
	currentresult = findMin(nextConfig, myMap);
      currentresult += findDist(marbnode, moveNode);
      if(currentresult < minresult)
	minresult = currentresult;
    }
    myMap[currentConfig.generateCode()] = minresult;
    return minresult;
  }
}

int main() {
  while(true) {
    int nodes;
    cin >> nodes;
    if(nodes == 0)
      break;
    vector<node*>* treeNodes = new vector<node*>;
    map<int, node*> nodeMap;
    vector<node*>* emptyNode = new vector<node*>;
    vector<node*>* marbleNode = new vector<node*>;
    for(int i = 1; i <= nodes; i++) {
      node* nextnode = new node(i, 0);
      treeNodes->push_back(nextnode);
      nodeMap[i] = nextnode;
    }
    for(int i = 0; i < nodes; i++) {
      int nextval;
      cin >> nextval;
      node* currentnode = nodeMap[nextval];
      int marbs;
      cin >> marbs;
      currentnode->marbles = marbs;
      if(marbs == 0)
	emptyNode->push_back(currentnode);
      else if(marbs > 1) {
	for(int j = 0; j < marbs - 1; j++)
	  marbleNode->push_back(currentnode);
      }
      int childrencount;
      cin >> childrencount;
      for(int j = 0; j < childrencount; j++) {
	int nextchildindex;
	cin >> nextchildindex;
	node* nextchild = nodeMap[nextchildindex];
	nextchild->parent = currentnode;
      }
    }
    config myConfig(marbleNode, emptyNode);
    map<string, int> myMap;
    int result = findMin(myConfig, myMap);
    cout << result << endl;
  }

  return 0;
}
