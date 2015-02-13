#include <cstdio>
#include <utility>
#include <cmath>
#define MAXN 1001
#define PI acos(-1.0)
#define EPS 1e-8

using namespace std;

typedef pair<double, double> point;
point points[MAXN];
double dist[MAXN][MAXN];
int n;

int sgn(double x, double y) {
  if(fabs(x - y) < EPS)
    return 0;
  else
    return x < y ? -1 : 1;
}

double distance(double pLat, double pLong, double qLat, double qLong) {
  pLat *= PI / 180;
  qLat *= PI / 180;
  qLong *= PI / 180;
  pLong *= PI / 180;
  return  acos(cos(pLat) * cos(pLong) * cos(qLat) * cos(qLong) +
	       cos(pLat) * sin(pLong) * cos(qLat) * sin(qLong) +
	       sin(pLat) * sin(qLat));
}

int main() {
  while(scanf("%d", &n) != EOF) {
    for(int i =0; i < n; i++) {
      scanf("%lf %lf", &points[i].first, &points[i].second);
    }
    for(int i=  0; i < n; i++) {
      dist[i][i] = 0.0;
      for(int j= i+1; j < n; j++) {
	dist[i][j] = dist[j][i] = distance(points[i].first, points[i].second, points[j].first, points[j].second);
      }
    }
    double minVal = 2e9;
    int resi = -1;
    for(int i = 0; i < n; i++) {
      double val = 0.0;
      for(int j = 0; j < n; j++) {
	val = fmax(val, dist[i][j]);
      }
      if(sgn(val, minVal) <= 0) {
	minVal = val;
	resi = i;
      }
    }
    printf("%.2f %.2f\n", points[resi].first, points[resi].second);
  }
  return 0;
}
