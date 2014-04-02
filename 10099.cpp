#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

struct node {
  int index;
  vector<int> adjacency;
  int maxincome;
  node(int i) : index(i), maxincome(0) {};
};

struct edge {
  node* a;
  int length;
  edge(node* one, int weight) : a(one), length(weight) {};
};

int main() {
  int cases = 1;
  while(true) {
    int vertices, edgecount;
    cin >> vertices >> edgecount;
    if(vertices == 0 && edgecount == 0)
      break;
    vector<node*> nodes;
    map<node*, vector<edge>* > adjacency;
    for(int i = 1; i <= vertices; i++) {
      node* currentnode = new node(i);
      nodes.push_back(currentnode);
      adjacency[currentnode] = new vector<edge>;
    }
    for(int i = 0; i < edgecount; i++) {
      int a, b, length;
      cin >> a >> b >> length;
      edge newedgeb(nodes[a-1], length);
      adjacency[nodes[b-1]]->push_back(newedgeb);
      edge newedgea(nodes[b-1], length);
      adjacency[nodes[a-1]]->push_back(newedgea);
    }
    int start, end, people;
    cin >> start >> end >> people;
    node* startNode = nodes[start - 1];
    startNode->maxincome = people;
    queue<node*> searchList;
    searchList.push(startNode);
    while(searchList.size() != 0) {
      node* currentNode = searchList.front();
      searchList.pop();
      vector<edge>* currentAdjacent = adjacency[currentNode];
      for(vector<edge>::iterator itr  = currentAdjacent->begin(); itr != currentAdjacent->end(); ++itr) {
	edge currentEdge = *itr;
	node* nextNode  = currentEdge.a;
	int nextIncome = currentNode->maxincome > currentEdge.length ? currentEdge.length : currentNode->maxincome;
	if(nextIncome > nextNode->maxincome) {
	  nextNode->maxincome = nextIncome;
	  searchList.push(nextNode);
	}
      }
    }
    int once = nodes[end-1]->maxincome - 1;
    cout << "Scenario #" << cases << endl;
    cout << "Minimum Number of Trips = " << (int) ceil((double) people / once) << endl;
    cout << endl;
    cases++;
  }
  return 0;
}
