#include <iostream>

using namespace std;

int main() {
  while(true) {
    int points;
    cin >> points;
    if(points == 0)
      break;
    int x, y;
    cin >> x >> y;
    for(int i = 0; i < points; i++) {
      int m, n;
      cin >> m >> n;
      if (x == m || y == n)
	cout << "divisa" << endl;
      // west
      else if (x > m) {
	cout << (y > n ? "SO" : "NO") << endl;
      }
      // east
      else {
	cout << (y > n ? "SE" : "NE") << endl;
      }
    }
  }
  return 0;
}
