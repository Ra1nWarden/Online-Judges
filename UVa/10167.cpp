#include <iostream>
#include <cmath>
#include <vector>

#define PI 3.141592653

using namespace std;

struct Point {
  Point(int a, int b) {
    x = a;
    y = b;
  };
  int x;
  int y;
};

bool checkEqualDivision(int a, int b, vector<Point*>& points) {
  int totalsize = points.size();
  int lessThan = 0;
  for(vector<Point*>::iterator itr = points.begin(); itr != points.end(); itr++) {
    double x = (double) (*itr)->x;
    double y = (double) (*itr)->y;
    if (x * a + b * y == 0)
      return false;
    else {
      double yonline;
      if (b == 0)
	yonline = 0;
      else
	yonline = - (a * x) / b;
      if (y < yonline)
	lessThan++;
    }
    if (lessThan > totalsize / 2)
      return false;
  }
  return (lessThan == totalsize / 2);
}

int main() {
  int cakeNo;
  while (cin >> cakeNo) {
    if(cakeNo == 0)
      break;
    vector<Point*> points;
    for(int i = 0; i < 2 * cakeNo; i++) {
      int x, y;
      cin >> x >> y;
      Point* this_point = new Point(x, y);
      points.push_back(this_point);
    }
    bool found = false;
    for(int b = -500; b <= 500; b++) {
      for(int a = -500; a <= 500; a++) {
	if (checkEqualDivision(a, b, points)) {
	  cout << a << " " << b << endl;
	  found = true;
	  break;
	}
      }
      if (found)
	break;
    }
  }
  return 0;
}
