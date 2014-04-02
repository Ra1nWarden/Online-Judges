#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include <cfloat>
#include <algorithm>
#include <iomanip>

using namespace std;

double resultVal;

struct point {
  double x, y;
  point(double a, double b):x(a),y(b) {};
};

double getDist(point& a, point& b) {
  double result = pow(a.x-b.x,2.0) + pow(a.y-b.y,2.0);
  result = sqrt(result);
  return result;
}

pair<int,int> findMin(vector<vector<double> >& distmatrix, vector<int>& selectedIndex) {
  int size = distmatrix.size();
  pair<int,int> result;
  result.first = 0;
  result.second = 0;
  double minval = DBL_MAX;
  for(int i= 0; i < size; i++) {
    for(int j = i + 1; j < size; j++) {
      double curval = distmatrix[i][j];
      if(curval != 0 && curval < minval) {
	if(selectedIndex.size() != 0) {
	  if(count(selectedIndex.begin(), selectedIndex.end(), i) == 0 && count(selectedIndex.begin(), selectedIndex.end(), j) == 0)
	    continue;
	}
	minval = curval;
	result.first = i;
	result.second = j;
      }
    }
  }
  resultVal += minval;
  return result;
}

void insertPair(pair<int, int>& insertpair, vector<int>& selectedIndex, vector<vector<double> >& distmatrix) { 
  int firstindex = insertpair.first;
  if(count(selectedIndex.begin(), selectedIndex.end(), firstindex) == 0) {
    for(int i=  0; i < selectedIndex.size(); i++) {
      int currentindex = selectedIndex[i];
      distmatrix[currentindex][firstindex] = 0;
      distmatrix[firstindex][currentindex] = 0;
    }
    selectedIndex.push_back(firstindex);
  }
  int secondindex = insertpair.second;
  if(count(selectedIndex.begin(), selectedIndex.end(), secondindex) == 0) {
    for(int i= 0; i < selectedIndex.size(); i++) {
      int currentindex = selectedIndex[i];
      distmatrix[currentindex][secondindex] = 0;
      distmatrix[secondindex][currentindex] = 0;
    }
    selectedIndex.push_back(secondindex);
  }
}

int main() {
  int cases;
  cin >> cases;
  cin >> ws;
  for(int i = 0; i < cases; i++) {
    if(i != 0)
      cout << endl;
    resultVal = 0;
    int points;
    cin >> points;
    vector<point> allpoints;
    for(int j = 0; j < points; j++) {
      double x, y;
      cin >> x >> y;
      point spoint(x, y);
      allpoints.push_back(spoint);
    }
    if(points == 1) {
      cout << "0.00" << endl;
      continue;
    }
    vector<vector<double> > distancematrix;
    for(int i= 0; i < points; i++) {
      vector<double> row;
      for(int j= 0; j < points; j++) {
	if(j <= i)
	  row.push_back(0);
	else
	  row.push_back(getDist(allpoints[i], allpoints[j]));
      }
      distancematrix.push_back(row);
    }
    vector<int> selectedIndex;
    while(selectedIndex.size() != points) {
      pair<int, int> nextInsert = findMin(distancematrix,selectedIndex);
      insertPair(nextInsert, selectedIndex, distancematrix);
    }
    cout.precision(2);
    cout << fixed << resultVal << endl;
  }
  return 0;
}
