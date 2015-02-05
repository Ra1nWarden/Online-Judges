#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool DEBUG = false;

int main() {
  int difference;
  while(cin >> difference) {
    int count;
    cin >> count;
    int years[count];
    memset(years, 0, sizeof years);
    int maxCount[count];
    memset(maxCount, 0, sizeof maxCount);
    for (int i= 0 ;i < count; i++) {
      int year;
      cin >> year;
      years[i] = year;
      int cutoff = year - difference + 1;
      int* cut = upper_bound(years, years+i+1, cutoff-1);
      if (DEBUG) {
	cout << "year is " << year << " difference is " << difference << endl;
	cout << "cutoff is " << cutoff << endl;
	cout << "current year is " << year << endl;
	cout << "cut is " << *cut << endl;
      }
      for (int* start = cut; start != years + i + 1; start++) {
	*(start - years + maxCount) = (*(start - years + maxCount) + 1);
      }
    }
    int maxA = 0, maxB = 0;
    for (int* index = maxCount; index != maxCount + count; index++) {
      if(*index > maxB) {
	maxB = *index;
	maxA = years[index - maxCount];
      }
    }
    int* upper = upper_bound(years, years + count, maxA + difference - 1);
    cout << maxB << " " << maxA << " " << *(--upper) << endl;;
  }
  return 0;
}
