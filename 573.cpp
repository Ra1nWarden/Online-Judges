#include <iostream>

using namespace std;

int main() {
  int h, u, d, f;
  while(cin >> h >> u >> d >> f) {
    if (h == 0)
      break;
    double updrop = (double) u * (double) f / (double) 100;
    double up = (double) u;
    double drop = (double) d;
    int day = 1;
    double dist = 0;
    while(true) {
      dist += up;
      if (dist > h) {
	cout << "success on day " << day << endl;
	break;
      }
      dist -= drop;
      if (dist < 0) {
	cout << "failure on day " << day << endl;
	break;
      }
      up -= updrop;
      if (up < 0)
	up = 0;
      day++;
    }
  }
  return 0;
}
