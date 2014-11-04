#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

map<string, vector<string> > graph;
map<string ,int> indexMap;
map<int, string> decodeMap;

typedef pair<string, string> con;

ostream& operator<<(ostream& oss, const con& connect) {
  oss << "(" << connect.first << "," << connect.second << ")";
  return oss;
}

int main() {
  int n;
  string line;
  int tc = 1;
  while(cin >> n && n) {
    graph.clear();
    indexMap.clear();
    decodeMap.clear();
    int index = 0;
    for(int i= 0; i < n; i++) {
      int x;
      cin >> x;
      vector<string> edges;
      string word;
      for(int j = 0; j < x; j++) {
	cin >> word;
	edges.push_back(word);
      }
      for(int j= 0; j < x; j++) {
	string start = edges[j];
	if(indexMap.count(start) == 0) {
	  indexMap[start] = index++;
	  decodeMap[index - 1] = start;
	}
	if(j+1 < x) {
	  string end = edges[j+1];
	  if(graph.count(start) == 0) {
	    vector<string> singleton;
	    singleton.push_back(end);
	    graph[start] = singleton;
	  }
	  else {
	    graph[start].push_back(end);
	  }
	  
	  if(indexMap.count(end) == 0) {
	    indexMap[end] = index++;
	    decodeMap[index-1] = end;
	  }
	}
      }
    }
    int message;
    cin >> message;
    for(int i = 0; i < message; i++) {
      string start, end;
      cin >> start >> end;
      graph[start].push_back(end);
    }

    bool adj[index][index];
    for(int i= 0; i < index; i++) {
      for(int j= 0; j < index; j++)
	adj[i][j] = false;
    }

    for(map<string, vector<string> >::iterator itr = graph.begin(); itr != graph.end(); itr++) {
      int x = indexMap[itr->first];
      for(int i= 0; i < itr->second.size(); i++) {
	string end = itr->second[i];
	int y= indexMap[end];
	adj[x][y] = true;
      }
    }

    // for(int i= 0; i < index; i++) {
    //   for(int j= 0; j < index; j++) {
    // 	cout << adj[i][j];
    //   }
    //   cout << endl;
    // }
    
    for(int k = 0; k < index; k++) {
      for(int i = 0; i < index; i++) {
	for(int j= 0; j < index; j++) {
	  adj[i][j] = adj[i][j] || (adj[i][k] && adj[k][j]);
	}
      }
    }

    // cout << "after running floyd warshall:" << endl;
    // for(int i= 0; i < index; i++) {
    //   for(int j= 0; j < index; j++) {
    // 	cout << adj[i][j];
    //   }
    //   cout << endl;
    // }

    vector<con> results;

    for(int i = 0; i < index; i++) {
      for(int j= i+1; j < index; j++) {
	//cout << "for i and j " << i << ", " << j << ": " << adj[i][j] << " and " << adj[j][i] << endl;
	if(!adj[i][j] && !adj[j][i]) {
	  results.push_back(make_pair(decodeMap[i], decodeMap[j]));
	}
      }
    }

    printf("Case %d, ", tc++);
    if(results.size() == 0)
      printf("no concurrent events.\n");
    else {
      printf("%lu concurrent events:\n", results.size());
      for(int i= 0; i < results.size() && i < 2; i++) {
	cout << results[i] << " ";
      }
      cout << endl;
    }

  }
  return 0;
}
