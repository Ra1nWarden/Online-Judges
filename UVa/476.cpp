#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <vector>
#define EPS 1e-8

using namespace std;

typedef pair<double, double> point;
typedef pair<point, point> rectangle;

vector<rectangle> recs;

int sgn(double x, double y) {
  if(fabs(x - y) < EPS)
    return 0;
  return x < y ? -1 : 1;
}

int main() {
  string line;
  while(getline(cin, line)) {
    if(line[0] == '*')
      break;
    stringstream ss(line.substr(1).c_str());
    double x1, y1, x2, y2;
    ss >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2)
      swap(x1, x2);
    if(y1 < y2)
      swap(y1, y2);
    recs.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
  }
  int pn = 1;
  while(getline(cin, line)) {
    double x, y;
    stringstream ss(line.c_str());
    ss >> x >> y;
    if(sgn(x , 9999.9) == 0 && sgn(y , 9999.9) == 0)
      break;
    bool contained = false;
    for(int i = 0; i < recs.size(); i++) {
      if(sgn(x, recs[i].first.first) >= 0 && sgn(x, recs[i].second.first) <= 0 && sgn(y , recs[i].first.second) <= 0 && sgn(y , recs[i].second.second) >= 0) {
	contained = true;
	printf("Point %d is contained in figure %d\n", pn, i+1);
      }
    }
    if(!contained) {
      printf("Point %d is not contained in any figure\n", pn);
    }
    pn++;
  }
  return 0;
}
