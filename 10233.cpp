#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

long long getRow(long long index) {
  long long result = 0;
  while(true) {
    long long sub = result * 2 + 1;
    if (sub > index) {
      break;
    }
    else {
      index -= sub;
      result++;
    }
  }
  return result;
}

bool isUpsideDown(long long index, long long row) {
  if (index == 0)
    return false;
  long long rowstart = 0;
  for(long long i = 1; i < row ; i++) {
    rowstart += (i * 2 - 1);
  }
  long long firstupsidedown = rowstart++;
  return (index - firstupsidedown) % 2 == 0;
}

int main() {
  long long start, end;
  while (cin >> start >> end) {
    if (end < start) {
      long long temp = start;
      start = end;
      end = temp;
    }
    long long smallrow = getRow(start);
    long long largerow = getRow(end);
    long long rowdiff = largerow - smallrow;
    long long correspond = start;
    for(long long i = smallrow + 1; i <= largerow; i++) {
      correspond += (i * 2);
    }
    long long coldiff = correspond > end ? (correspond - end) : (end - correspond);
    double rowdist = (rowdiff - 1) * 0.5 * sqrt(3);
    if (rowdiff % 2 == 0) {
      rowdist += 0.5 * sqrt(3);
    }
    else {
      if(isUpsideDown(start, smallrow)) {
	rowdist += 2 / sqrt(3);
      }
      else {
	rowdist += 1 / sqrt(3);
      }
    }
    double coldist = (double) coldiff / 2;
    if (coldiff % 2 != 0) {
      if(isUpsideDown(correspond, largerow)) {
	rowdist += (0.5 / sqrt(3));
      }
      else {
	rowdist -= (0.5 / sqrt(3));
      }
    }
    double dist = sqrt(pow(rowdist, 2) + pow(coldist, 2));
    printf("%.3f\n", dist);
  }
  return 0;
}
