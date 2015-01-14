#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Point {
  double x, y;
  Point(double _x, double _y) : x(_x), y(_y) {};
  Point operator-(const Point& b) const {
    return Point(x - b.x, y - b.y);
  };
  Point operator+(const Point& b) const {
    return Point(x + b.x, y + b.y);
  };
  // dot product
  double operator*(const Point& b) const {
    return x * b.x + y * b.y;
  };
  Point operator*(double m) const {
    return Point(x * m, y * m);
  };
  // cross product
  double operator^(const Point& b) const {
    return x * b.x - y * b.y;
  };
};

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    int n;
    cin >> n;
    vector<double> radii;
    for(int i = 0; i < n; i++) {
      double r;
      cin >> r;
      radii.push_back(r);
    }
    if(radii.size() == 1) {
      printf("%.3f\n", radii.front() * 2);
      continue;
    }
    sort(radii.begin(), radii.end());
    double result = 1e9;
    do {
      double res = 0;
      vector<Point> origins;
      //cout << "current combi: ";
      for(int i = 0; i < radii.size(); i++) {
	//cout << radii[i] << " ";
	if(origins.empty()) {
	  res = max(res, radii[i] * 2);
	  origins.push_back(Point(radii[i], radii[i]));
	} else {
	  double xcoord = radii[i];
	  for(int j = 0; j < origins.size(); j++) {
	    Point p = origins[j];
	    double add = sqrt(pow(radii[j] + radii[i], 2) - pow(radii[j] - radii[i], 2));
	    xcoord = max(xcoord, p.x + add);
	  }
	  res = max(res, xcoord + radii[i]);
	  origins.push_back(Point(xcoord, radii[i]));
	}
      }
      //cout << " res is " << res << endl;
      result = min(result, res);
    } while(next_permutation(radii.begin(), radii.end()));
    printf("%.3f\n", result);
  }
  return 0;
}
