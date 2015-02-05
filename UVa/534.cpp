#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <cstdio>
#define EPS 1e-8

using namespace std;

typedef pair<int, int> coord;

double calcDistance(const coord& one, const coord& two) {
  double x1, x2, y1, y2;
  x1 = (double) one.first;
  y1 = (double) one.second;
  x2 = (double) two.first;
  y2 = (double) two.second;
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
  int n;
  int tc = 1;
  while(cin >> n && n) {
    //cout << "n is " << n << endl;
    double adj[n][n];
    vector<coord> points;
    for(int i= 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      points.push_back(make_pair(x, y));
    }
    for(int i = 0; i < n; i++) {
      for(int j= i; j < n; j++) {
	if(j == i) {
	  adj[i][j] = 0;
	  continue;
	}
	coord firstPoint = points[i];
	coord secondPoint = points[j];
	adj[i][j] = adj[j][i] = calcDistance(firstPoint, secondPoint);
      }
    }

    for(int k = 0; k < n; k++) {
      for(int i= 0; i < n; i++) {
	for(int j= 0; j < n; j++) {
	  adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
	}
      }
    }

    printf("Scenario #%d\n", tc++);
    printf("Frog Distance = %.3f\n\n", adj[0][1]);
  } 
  return 0;
}
