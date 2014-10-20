#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>

using namespace std;

bool DEBUG = false;

int main() {
  int cases;
  cin >> cases;
  for(int i= 0; i < cases; i++) {
    int stops;
    cin >> stops;
    int v[stops-1];
    for(int j = 0; j < stops-1; j++) {
      int scene;
      cin >> scene;
      v[j] = scene;
    }
    // first a stops, 0 -> not take a, 1 -> take a
    int f[stops+1][2]; // max values
    int start[stops+1][2]; // max values start
    int end[stops+1][2]; // max value end
    memset(f, INT_MIN, sizeof f);
    memset(start, -1, sizeof start);
    memset(end, -1, sizeof end);
    f[0][0] = 0;
    f[1][0] = 0;
    f[1][1] = v[0];
    start[1][1] = 1;
    end[1][1] = 2;
    for(int j = 2; j <= stops-1; j++) {
      // f[j][0]
      int a = f[j-1][0];
      int b = f[j-1][1];
      if(a > b) {
	f[j][0] = a;
	start[j][0] = start[j-1][0];
	end[j][0] = end[j-1][0];
      }
      else if (a == b) {
	f[j][0] = a;
	if(end[j-1][0] - start[j-1][0] > end[j-1][1] - start[j-1][1]) {
	  start[j][0] = start[j-1][0];
	  end[j][0] = end[j-1][0];
	} else if (end[j-1][0] - start[j-1][0]  == end[j-1][1] - start[j-1][1]) {
	  start[j][0] = start[j-1][0] < start[j-1][1] ? start[j-1][0] : start[j-1][1];
	  end[j][0] = start[j-1][0] < start[j-1][1] ? end[j-1][0] : end[j-1][1];
	} else {
	  start[j][0] = start[j-1][1];
	  end[j][0] = end[j-1][1];
	}
      }
      else {
	f[j][0] = b;
	start[j][0] = start[j-1][1];
	end[j][0] = end[j-1][1];
      }
      // f[j][1]
      a = f[j-1][1] + v[j-1];
      b = v[j-1];
      if(a > b) {
	f[j][1] = a;
	start[j][1] = start[j-1][1];
	end[j][1] = j+1;
      } else if (a == b) {
	f[j][1] = a;
	start[j][1] = start[j-1][1];
	end[j][1] = j+1;
      } else {
	f[j][1] = b;
	start[j][1] = j;
	end[j][1] = j+1;
      }
    }
    if(DEBUG) {
      for(int j = 0; j < stops; j++) {
	cout << f[j][0] << ": " << start[j][0] << ", " << end[j][0] << endl;
	cout << f[j][1] << ": " << start[j][1] << ", " << end[j][1] << endl;
	cout << endl;
      }
    }
    int notlast = f[stops-1][0];
    int last = f[stops-1][1];
    int result = -1;
    int resultstart = -1;
    int resultend = -1;
    if(notlast > last) {
      result = notlast;
      resultstart = start[stops-1][0];
      resultend = end[stops-1][0];
    } else if (notlast == last) {
      result = notlast;
      if(end[stops-1][0] - start[stops-1][0] > end[stops-1][1] - start[stops-1][1]) {
	resultstart = start[stops-1][0];
	resultend = end[stops-1][0];
      } else if (end[stops-1][0] - start[stops-1][0]  == end[stops-1][1] - start[stops-1][1]) {
	resultstart = start[stops-1][0] < start[stops-1][1] ? start[stops-1][0] : start[stops-1][1];
	resultend = start[stops-1][0] < start[stops-1][1] ? end[stops-1][0] : end[stops-1][1];
      } else {
	  resultstart = start[stops-1][1];
	  resultend = end[stops-1][1];
      }
    } else {
      result = last;
      resultstart = start[stops-1][1];
      resultend = end[stops-1][1];
    }
    if(result > 0) {
      printf("The nicest part of route %d is between stops %d and %d\n", i+1, resultstart, resultend);
    } else {
      printf("Route %d has no nice parts\n", i+1);
    }
  }
  return 0;
}
