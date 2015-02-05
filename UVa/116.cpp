#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point {
  int i, j;
  long long value;
  vector<point*> previous;
  vector<point*> next;
  long long minval;
  point(long long a) : value(a), minval(a) {};
};

bool compare(const point* a, const point* b) {
  return (a->i < b->i);
}

int main() {
  while(!cin.eof()) {
    int row, col;
    cin >> row >> col;
    vector<vector<point*> > grid;
    for(int i = 0; i < row; i++) {
      vector<point*> currentrow; 
      for(int j = 0; j < col; j++) {
	long long val;
	cin >> val;
	point* newpoint = new point(val);
	newpoint->i = i;
	newpoint->j = j;
	currentrow.push_back(newpoint);
      }
      grid.push_back(currentrow);
    }
    for(int j = 1; j< col; j++) {
      for(int i = 0; i < row; i++) {
	point* currentpoint = grid[i][j];
	vector<point*> previous;
	long long minval = grid[i][j-1]->minval;
	previous.push_back(grid[i][j-1]);
	point* up = grid[(i + row -1)%row][j-1];
	if(up->minval < minval) {
	  minval = up->minval;
	  previous.clear();
	  previous.push_back(up);
	}
	else if(up->minval == minval) {
	  if(count(previous.begin(), previous.end(), up) == 0)
	    previous.push_back(up);
	}
	point* down = grid[(i+1)%row][j-1];
	if(down->minval < minval) {
	  minval = down->minval;
	  previous.clear();
	  previous.push_back(down);
	}
	else if(down->minval == minval) {
	  if(count(previous.begin(), previous.end(), down) == 0)
	    previous.push_back(down);
	}
	currentpoint->minval = minval + currentpoint->value;
	currentpoint->previous = previous;
      }
    }


    long long minval = grid[0][col-1]->minval;
    vector<point*> minpoints;
    minpoints.push_back(grid[0][col-1]);
    for(int i = 1; i < row; i++) {
      point* currentpoint = grid[i][col-1];
      if(currentpoint->minval == minval)
	minpoints.push_back(currentpoint);
      else if(currentpoint->minval < minval) {
	minval = currentpoint->minval;
	minpoints.clear();
	minpoints.push_back(currentpoint);
      }
    }


    for(int j = col - 1; j > 0; j--) {
      vector<point*> nextitr;
      for(int i = 0; i < minpoints.size(); i++) {
	point* currentpoint = minpoints[i];
	for(int k = 0; k< currentpoint->previous.size(); k++) {
	  point* currentprev = currentpoint->previous[k];
	  currentprev->next.push_back(currentpoint);
	  if(count(nextitr.begin(), nextitr.end(), currentprev) == 0)
	    nextitr.push_back(currentprev);
	}
      }
      minpoints = nextitr;
    }

    for(int j = 0; j < col; j++) {
     sort(minpoints.begin(), minpoints.end(), compare);
     point* currentpoint = minpoints[0];
     cout << currentpoint->i + 1;
     if(j == col - 1)
       break;
     cout << " ";
     minpoints = currentpoint->next;
    }
    cout << endl;
    cout << minval << endl;
    
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++)
	delete grid[i][j];
    }
    cin >> ws;
  }
  return 0;
}
