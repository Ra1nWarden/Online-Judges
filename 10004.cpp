#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkVector(vector<bool>& colored) {
  for(int i = 0; i < colored.size(); i++) {
    if(!colored[i]) {
      return false;
    }
  }
  return true;
}

int main() {
  while(true) {
    int vertices, edges;
    cin >> vertices;
    if(vertices == 0)
      break;
    cin >> edges;
    vector<int> color(vertices);
    for(int i = 0 ;i  < vertices; i++)
      color[i] = 0;
    vector<vector<int> > adjacency(vertices);
    for(int i = 0 ;i < edges; i++) {
      int a, b;
      cin >> a >> b;
      adjacency[a].push_back(b);
      adjacency[b].push_back(a);
    }
    color[0] = 1;
    bool success = true;
    vector<bool> colored(vertices);
    for(int i = 0 ; i < vertices; i++)
      colored[i] = false;
    colored[0] = true;
    vector<int> nextcolor = adjacency[0];
    int fillcolor = -color[0];
    while(!checkVector(colored)) {
      vector<int> newnextcolor;
      for(int i = 0; i < nextcolor.size(); i++) {
	int nextindex = nextcolor[i];
	color[nextindex] = fillcolor;
	colored[nextindex] = true;
	vector<int> nextadjacent = adjacency[nextindex];
	for(int j = 0; j < nextadjacent.size(); j++) {
	  if(color[nextadjacent[j]] == 0) {
	    if(count(newnextcolor.begin(), newnextcolor.end(), j) == 0)
	      newnextcolor.push_back(nextadjacent[j]);
	  }
	  else {
	    if(color[nextadjacent[j]] != -fillcolor) {
	      success = false;
	      break;
	    }
	  }	  
	}
	if(!success)
	  break;
      }
      if(!success)
	break;
      nextcolor = newnextcolor;
      fillcolor = -fillcolor;
    }
    if(success)
      cout << "BICOLORABLE." << endl;
    else
      cout << "NOT BICOLORABLE." << endl;
  }
  return 0;
}
