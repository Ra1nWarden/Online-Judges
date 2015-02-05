#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <cmath>
#include <sstream>
#include <queue>
#define EPSILON 1E-8

using namespace std;

bool edge[1024][1024];
int bfsIndex[1024];
int n;

double dist(pair<double, double> p1, pair<double, double> p2) {
  return sqrt(pow(fabs(p1.first - p2.first) + EPSILON, 2) + pow(fabs(p1.second - p2.second) + EPSILON, 2));
}

int bfs(int start, int end) {
  queue<int> q;
  q.push(start);
  bfsIndex[start] = 0;
  while(!q.empty() && bfsIndex[end] == -1) {
    int next = q.front();
    q.pop();
    for(int i= 0; i < n; i++) {
      if(edge[next][i] && bfsIndex[i] == -1) {
	bfsIndex[i] = bfsIndex[next] + 1;
	q.push(i);
      }
    }
  }
  return bfsIndex[end];
}

int main() {
  double v, m;
  while(cin >> v >> m && (v || m)) {
    // cout << "v and m is " << v <<  ", " << m << endl;
    vector<pair<double, double> > points;
    string line;
    double minDist = v * m * 60.0;
    memset(edge, false, sizeof edge);
    getline(cin, line);
    while(true) {
      getline(cin, line);
      if(line.empty())
	break;
      istringstream iss(line.c_str());
      double x, y;
      iss >> x >> y;
      points.push_back(make_pair(x, y));
      for(int i= 0; i < points.size() - 1; i++) {
	if(dist(points[i], points.back()) < minDist + EPSILON) {
	  edge[i][points.size() - 1] = true;
	  edge[points.size() - 1][i] = true;
	}
      }
    }
    n = points.size();
    memset(bfsIndex, -1, sizeof bfsIndex);
    // for(int i = 0; i < n; i++) {
    //   for(int j= 0; j < n; j++) {
    // 	cout << edge[i][j];
    //   }
    //   cout << endl;
    // }
    // cout << endl;
    int result = bfs(0, 1);
    if(result == -1)
      cout << "No." << endl;
    else
      cout << "Yes, visiting " << result-1 << " other holes." << endl;
  }
  return 0;
}
