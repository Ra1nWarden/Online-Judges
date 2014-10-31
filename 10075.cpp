#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <utility>
#include <cstdio>

#define INF 2e8
#define EPS 1e-8
#define PI 3.141592653589793
#define RADIUS 6378

using namespace std;

map<string, pair<double, double> > cityMap;
map<string, int> indexMap;

double dist[101][101];

double distanceCalc(const pair<double, double>& one, const pair<double, double>& two) {
  double lat1 = fabs(one.first);
  lat1 = lat1 / 180 * PI;
  double lat2 = fabs(two.first);
  lat2 = lat2 / 180 * PI;
  double lon1 = one.second;
  lon1 = lon1 / 180 * PI;
  double lon2 = two.second;
  lon2 = lon2 / 180 * PI;

  return RADIUS*sqrt(2-2*(cos(lat1)*cos(lat2)*cos(lon1-lon2)+sin(lat1)*sin(lat2)));
}

int main() {
  int n, m, q;
  int tc = 1;
  while(cin >> n >> m >> q >> ws && (n || m || q)) {
    if(tc > 1)
      cout << endl;
    string line;
    for(int i= 0; i < n; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      string name;
      double x,y;
      iss >> name >> x >> y;
      cityMap[name] = make_pair(x, y);
      indexMap[name] = i;
    }
    for(int i= 0; i < n; i++) {
      for(int j= 0; j < n; j++) {
	dist[i][j] = INF;
      }
    }
    for(int i= 0; i < m; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      string start, end;
      iss >> start >> end;
      pair<double, double> startCoord = cityMap[start];
      pair<double, double> endCoord = cityMap[end];
      dist[indexMap[start]][indexMap[end]] = distanceCalc(startCoord, endCoord);
    }

    for(int k= 0; k < n; k++) {
      for(int i= 0; i < n; i++) {
	for(int j= 0; j < n; j++) {
	  dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}
      }
    }

    printf("Case #%d\n", tc++);

    for(int i= 0; i < q; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      string start, end;
      iss >> start >> end;
      double result = dist[indexMap[start]][indexMap[end]];
      if(result != INF)
	printf("%d km\n", (int) (result + 0.5 + EPS));
      else
	printf("not route exists\n");
    }
    
  }
  return 0;
}
