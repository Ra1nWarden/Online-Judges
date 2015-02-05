#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double getDist(double ax, double ay, double bx, double by) {
  return sqrt(pow((ax - bx), 2) + pow((ay - by), 2));
}

int main() {
  int holes;
  while(cin >> holes) {
    double gx, gy, dx, dy;
    bool success = false;
    cin >> gx >> gy >> dx >> dy;
    for(int i = 0; i < holes; i++) {
      double x, y;
      cin >> x >> y;
      if(success) {
	continue;
      }
      double gdist = getDist(gx, gy, x, y);
      double ddist = getDist(dx, dy, x, y);
      if (gdist * 2 <= ddist) {
	success = true;
	printf("The gopher can escape through the hole at (%.3f,%.3f).\n", x, y);
      }
    }
    if(!success) {
      cout << "The gopher cannot escape." << endl;
    }
  }
  return 0;
}
