#include <iostream>
#include <map>

using namespace std;

struct point {
  int x, y;
  bool operator<(const point& b) const {
    return (x<b.x || y<b.y);
  };
};

int main() {
  point a, b;
  a.x = 0;
  a.y = 1;
  b.x = 0;
  b.y = 1;
  map<point, int> myMap;
  myMap[a] = 3;
  cout << myMap[b] << endl;
  return 0;
}
