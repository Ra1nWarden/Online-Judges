#include <cstdio>
#include <cmath>
#define PI acos(-1.0)
#define RADIUS 6371009

using namespace std;

double pLat, pLong, qLat, qLong;

double distanceSphere() {
  return RADIUS * acos(cos(pLat) * cos(pLong) * cos(qLat) * cos(qLong) +
		       cos(pLat) * sin(pLong) * cos(qLat) * sin(qLong) +
		       sin(pLat) * sin(qLat));
}

double distanceSpace() {
  return RADIUS * sqrt(2 - 2 * (cos(pLat) * cos(qLat) * cos(pLong - qLong) + sin(pLat) * sin(qLat)));
}

int main() {
  int tc;
  scanf("%d", &tc);
  for(int i = 0; i < tc; i++) {
    scanf("%lf %lf %lf %lf", &pLat, &pLong, &qLat, &qLong);
    pLat *= PI / 180;
    pLong *= PI / 180;
    qLat *= PI / 180;
    qLong *= PI / 180;
    printf("%.0f\n", distanceSphere() - distanceSpace());
  }
  return 0;
}
