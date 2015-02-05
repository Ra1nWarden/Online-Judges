#include <iostream>
#include <cstring>
#include <cstdio>
#define EPS 1e-8
#define INF 2e8

using namespace std;

int dist[101][101];

int main() {
  int x, y;
  int tc = 1;
  while(cin >> x >> y && (x || y)) {
    for(int i = 1; i <= 100; i++) {
      for(int j = 1; j <= 100; j++) {
	dist[i][j] = INF;
      }
    }
    dist[x][y] = 1;
    while(cin >> x >> y && (x || y)) {
      dist[x][y] = 1;
    }
    
    for(int k = 1; k <= 100; k++) {
      for(int i= 1; i <= 100; i++) {
	for(int j=  1; j <= 100; j++) {
	  dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}
      }
    }

    // for(int i=  1; i <= 100; i++) {
    //   for(int j= 1; j <= 100; j++)
    // 	cout << dist[i][j] << " ";
    //   cout << endl;
    // }

    double result = 0;
    double n = 0.0;
    
    for(int i = 1; i <= 100; i++) {
      for(int j = 1; j <= 100; j++) {
	if(i != j && dist[i][j] != INF) {
	  result += dist[i][j];
	  n += 1.0;
	}
      }
    }

    
    
    printf("Case %d: average length between pages = %.3f clicks\n", tc++, (result / n) + EPS);
    
  }
  return 0;
}
