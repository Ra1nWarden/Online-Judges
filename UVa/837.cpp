#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <cfloat>

using namespace std;

struct Point {
  Point(double x, double y) {
    this->x = x;
    this->y = y;
  };
  double x;
  double y;
};

struct Line {
  Line(Point* start, Point* end, double rate) {
    this->start = start;
    this->end = end;
    this->reflex_index = rate;
  };
  bool checkOverlap(double lower, double upper) {
    return !(start->x >= upper || end->x <= lower); 
  };
  Point* start;
  Point* end;
  double reflex_index;
};

double calculateRate(double lower, double upper, vector<Line*>& lines) {
  double result = 1;
  for(vector<Line*>::iterator itr = lines.begin(); itr != lines.end(); itr++) {
    if ((*itr)->checkOverlap(lower, upper)) {
      result *= (*itr)->reflex_index;
    }
  }
  return result;
}

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    if(i != 0)
      cout << endl;
    int lines_count;
    cin >> lines_count;
    vector<Line*> lines;
    set<double> segs;
    for(int j = 0; j < lines_count; j++) {
      double x1, y1, x2, y2, r;
      cin >> x1 >> y1 >> x2 >> y2 >> r;
      segs.insert(x1);
      segs.insert(x2);
      Point* one = new Point(x1, y1);
      Point* two = new Point(x2, y2);
      Line* current_line;
      if (one->x < two->x)
	current_line = new Line(one, two, r);
      else
	current_line = new Line(two, one, r);
      lines.push_back(current_line);
    }
    double prev = DBL_MIN;
    cout << segs.size()+1 << endl;
    for(set<double>::iterator itr = segs.begin(); itr != segs.end(); itr++) {
      double lowerbound, upperbound;
      lowerbound = prev;
      upperbound = *itr;
      if(itr == segs.begin())
	printf("-inf %.3f %.3f\n", upperbound, calculateRate(lowerbound, upperbound, lines));
      else
	printf("%.3f %.3f %.3f\n", lowerbound, upperbound, calculateRate(lowerbound, upperbound, lines));
      prev = *itr;
    }
    printf("%.3f +inf %.3f\n", *segs.rbegin(), calculateRate(*segs.rbegin(), DBL_MAX, lines));
  }
  return 0;
}
