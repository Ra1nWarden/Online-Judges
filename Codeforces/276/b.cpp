#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  long long xmin, xmax, ymin, ymax;
  long long x, y;
  cin >> x >> y;
  xmin = xmax = x;
  ymin = ymax = y;
  n--;
  while(n--) {
    cin >> x >> y;
    if(x < xmin)
      xmin = x;
    if(x > xmax)
      xmax = x;
    if(y < ymin)
      ymin = y;
    if(y > ymax)
      ymax = y;
  }
  //cout << xmin << ", " << xmax << endl;
  //cout << ymin << ", " << ymax << endl;
  long long side = max(ymax - ymin, xmax - xmin);
  cout << side * side << endl;
  return 0;
}

