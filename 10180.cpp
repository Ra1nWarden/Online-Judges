#include <iostream>
#include <cmath>
#include <vector>
#include <climits>

using namespace std;

#define PI 3.14159265

struct Point {
  Point(double a, double b) { x = a; y = b; };
  double x;
  double y;
};

vector<double> solveEquation(double a, double b, double c) {
  vector<double> result;
  double x1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
  double x2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
  result.push_back(x1);
  result.push_back(x2);
  return result;
}

vector<Point*> getTangentPoint(double radius, double x, double y) {
  double a = pow(x, 2) + pow(y, 2);
  double b = (-2) * x * pow(radius, 2);
  double c = pow(radius, 4) - pow(radius, 2) * pow(y, 2);
  vector<double> xresults = solveEquation(a, b, c);
  vector<Point*> result;
  for(int i = 0; i < 2; i++) {
    double x = xresults[i];
    double y = sqrt(pow(radius, 2) - pow(x, 2));
    Point* newpoint = new Point(x, y);
    result.push_back(newpoint);
  }
  return result;
}

double getArcDist(Point*& one, Point*& two, double radius) {
  double a1, b1, c1;
  if (one->x == 0) {
    a1 = 1;
    b1 = 0;
    c1 = 0;
  }
  else if (one->y == 0) {
    a1 = 0;
    b1 = 1;
    c1 = 0;
  }
  else {
    a1 = - (one->y / one->x);
    b1 = 1;
    c1 = 0;
  }
  double a2, b2, c2;
  if (two->x == 0) {
    a2 = 1;
    b2 = 0;
    c2 = 0;
  }
  else if (two->y == 0) {
    a2 = 0;
    b2 = 1;
    c2 = 0;
  }
  else {
    a2 = - (two->y / two->x);
    b2 = 1;
    c2 = 0;
  }
  double angle = atan((a1 * b2 - a2 * b1) / (a1 * a2 + b1 * b2));
  cout << "Point1 " << one->x << " " << one->y << endl;
  cout << "Point2 " << two->x << " " << two->y << endl;
  cout << "angle is " << angle / PI * 180 << endl;
  return abs(radius * angle);
}

bool checkForNotLineTouch(double x1, double y1, double x2, double y2, double radius) {
  double a = pow(x2 - x1, 2) + pow(y2 - y1, 2);
  double b = 2 * x1 * (x2 - x1) + 2 * y1 * (y2 - y1);
  double c = pow(x1, 2) + pow(y1, 2) - pow(radius, 2);
  if ((pow(b, 2) - 4 * a * c) < 0)
    return true;
  else {
    double sol1 = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    double sol2 = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
    if ((sol1 >= 0 && sol1 <= 1) && (sol2 >= 0 && sol2 <= 1)) {
      if(sol1 == sol2)
	return true;
      else
	return false;
    }
    else
      return true;
  }
}

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    double x1, y1, x2, y2, r;
    cin >> x1 >> y1 >> x2 >> y2 >> r;
    if(!checkForNotLineTouch(x1, y1, x2, y2, r)) {
      vector<Point*> first = getTangentPoint(r, x1, y1);
      vector<Point*> second = getTangentPoint(r, x2, y2);
      cout << "second first x: " << second[0]->x << " " << second[0]->y << endl;
      cout << "second second x: " << second[1]->x << " " << second[1]->y << endl;
      double minArc = -1;
      for(int j = 0; j < 2; j++) {
	for(int k = 0; k < 2; k++) {
	  Point* pointone = first[j];
	  Point* pointtwo = second[k];
	  double arclength = getArcDist(pointone, pointtwo, r);
	  if (arclength == 0)
	    arclength = PI * r;
	  cout << "arclength = " << arclength << endl;
	  if(minArc < 0 && arclength != 0) {
	    minArc = arclength;
	  }
	  else if (arclength < minArc && arclength != 0){
	    minArc = arclength;
	  }
	}
      }
      double tanLength1 = sqrt(pow(x1, 2) + pow(y1, 2) - pow(r, 2));
      double tanLength2 = sqrt(pow(x2, 2) + pow(y2, 2) - pow(r, 2));
      cout << "tan1: " << tanLength1 << " tan2: " << tanLength2 << " arc: " << minArc << endl;
      printf("%.3f\n", tanLength1 + tanLength2 + minArc);
    }
    else {
      double dist = sqrt(pow(y1 - y2, 2) + pow(x1 - x2, 2));
      printf("%.3f\n", dist);
    }
  }
  return 0;
}
