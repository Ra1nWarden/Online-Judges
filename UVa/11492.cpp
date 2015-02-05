#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <utility>
 
using namespace std;

bool DEBUG = false;

struct Node {
  string name;
  int value;
  map<char, int> charMin;
  char prevChar;
  Node(string n) : name(n), value(-1) {};
  bool operator<(const Node& another) const {
    if (value == -1)
      return true;
    if (another.value == -1)
      return false;
    return value > another.value;
  };
  multimap<string, string> connectionMap;
};

int main() {
  int edges;
  while(cin >> edges) {
    if (edges == 0)
      break;
    map<string, Node*> nodes;
    string start, end;
    cin >> start >> end;
    Node* startNode = new Node(start);
    Node* endNode = new Node(end);
    nodes[start] = startNode;
    nodes[end] = endNode;
    for (int i = 0; i < edges; i++) {
      string side1, side2, word;
      cin >> side1 >> side2 >> word;
      if (nodes.count(side1) == 0) {
	Node* newnode = new Node(side1);
	nodes[side1] = newnode;
      }
      if (nodes.count(side2) == 0) {
	Node* newnode = new Node(side2);
	nodes[side2] = newnode;
      }
      nodes[side1]->connectionMap.insert(pair<string, string>(side2, word));
      nodes[side2]->connectionMap.insert(pair<string, string>(side1, word));
    }
    priority_queue<Node> nodeQ;
    map<string, bool> out;
    nodes[start]->value = 0;
    nodes[start]->charMin[' '] = 0;
    nodes[start]->prevChar = ' ';
    Node currentNode = *nodes[start];
    nodeQ.push(currentNode);
    if (DEBUG) {
      for(map<string, Node*>::iterator itr = nodes.begin(); itr != nodes.end(); itr++) {
	cout << "displaying " << itr->first << endl;
	multimap<string, string> connects = itr->second->connectionMap;
	for(multimap<string, string>::iterator itr2 = connects.begin(); itr2 != connects.end(); itr2++) {
	  cout << itr2->first << " " << itr2->second << endl;
	}
      }
    }
    while (!nodeQ.empty()) {
      currentNode = nodeQ.top();
      nodeQ.pop();
      string currentNodeName = currentNode.name;
      if (currentNode.value == -1)
	break;
      multimap<string, string>* currentConn = &currentNode.connectionMap;
      if (DEBUG) 
	cout << "current Node is " << currentNodeName << " with prevChar " << currentNode.prevChar << endl;
      for(multimap<string, string>::iterator itr = currentConn->begin(); itr != currentConn->end(); itr++) {
	string nextNode = itr->first;
	string conStr = itr->second;
	if (DEBUG)
	  cout << "next node is " << nextNode << " connected by " << conStr << endl;
	int length = conStr.length();
	int newlength = length + currentNode.value;
	char newChar = conStr[0];
	if (out.count(nextNode) == 0) {
	  if (DEBUG) cout << "if" << endl;
	  int nextValue = nodes[nextNode]->value;
	  if ((nextValue == -1 || nodes[nextNode]->charMin.count(newChar) == 0 || nodes[nextNode]->charMin[newChar] > newlength) && newChar != currentNode.prevChar) {
	    if (DEBUG) {
	      cout << "updating " << nextNode << " with " << conStr << endl;
	      cout << "new char is " << newChar << " and length is " << newlength << endl;
	    }
	    nodes[nextNode]->value = newlength;
	    nodes[nextNode]->charMin[newChar] = newlength;
	    nodes[nextNode]->prevChar = newChar;
	    nodeQ.push(*nodes[nextNode]);
	  }
	}
	else if (nodes[nextNode]->charMin.count(newChar) == 0) {
	  if (DEBUG) cout << "else" << endl;
	  if (newChar != currentNode.prevChar) {
	    if (DEBUG) {
	      cout << "updating " << nextNode << " with " << conStr << endl;
	      cout << "new char is " << newChar << " and length is " << newlength << endl;
	    }
	    nodes[nextNode]->value = newlength;
	    nodes[nextNode]->charMin[newChar] = newlength;
	    nodes[nextNode]->prevChar = newChar;
	    nodeQ.push(*nodes[nextNode]);
	  }
	}
      }
      out[currentNodeName] = true;
    }
    if (out[end]) {
      if (DEBUG) cout << "found" << endl;
      int result = -1;
      map<char, int>* paths = &nodes[end]->charMin;
      for(map<char, int>::iterator itr = paths->begin(); itr != paths->end(); itr++) {
	int thisLength = itr->second;
	if (DEBUG) cout << itr->first << " has length " << itr->second << endl;
	if (result == -1)
	  result = thisLength;
	else if (result > thisLength)
	  result = thisLength;
      }
      cout << result << endl;
    }
    else
      cout << "impossivel" << endl;
  }
  return 0;
}
