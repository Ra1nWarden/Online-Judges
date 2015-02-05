#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;

int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string weeks[] = {"Sunday", "Monday",  "Tuesday",  "Wednesday",  "Thursday", "Friday", "Saturday"};
string months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

bool leap(int y) {
  if(y >= 1752) {
    if(y % 100 == 0) {
      return y % 400 == 0;
    }
  }
  return y % 4 == 0;
}

bool notexist(int d, int m, int y) {
  if(y == 1752 && m == 9) {
    return d > 2 && d < 14;
  }
  return false;
}

bool beforechange(int d, int m, int y) {
  if(y < 1752)
    return true;
  if(y == 1752) {
    if(m < 9)
      return true;
    else if(m == 9)
      return d == 1 || d == 2;
    else
      return false;
  }
  return false;
}

int main() {
  int m, d, y;
  while(cin >> m >> d >> y && (m || d || y)) {
    if(m < 1 || m > 12 || d > days[m] || d < 1 || notexist(d, m, y) || y < 1) {
      printf("%d/%d/%d is an invalid date.\n", m, d, y);
      continue;
    }
    if(m == 2 && d == 29 && !leap(y)) {
      printf("%d/%d/%d is an invalid date.\n", m, d, y);
      continue;
    }
    int total = 365 * abs(y - 2014);
    int leaps = abs((y / 4 - y / 100  + y / 400) - (2014 / 4 - 2014 / 100 + 2014/ 400));
    //cout << "solid years " << total << endl;
    //cout << "leaps " << leaps << endl;
    total += leaps;
    if(beforechange(d, m, y)) {
      total -= 11;
      total += abs((y / 100 - y / 400) - (1752 / 100 - 1752 / 400));
    }
    int offset = 0;
    for(int i = 1; i < m; i++) {
      if(i == 2) {
	offset += 28;
	continue;
      }
      offset += days[i];
    }
    //cout << offset << endl;
    offset += (d - 1);
    if(m == 2 && d == 29)
      offset-=1;
    //cout << "offset is " << offset << endl;
    int week = 3;
    if(y >= 2014) {
      total += offset;
      if(leap(y) && (m < 2 || (m == 2 && d < 29)))
	total-=1;
      //cout << "total is " << total << " for year " << y << endl;
      week = (3 + (total % 7)) % 7;
    } else {
      total -= offset;
      if(leap(y) && (m < 2 || (m == 2 && d < 29)))
	total+=1;
      //cout << "total is " << total << " for year " << y << endl;
      week = (3 - (total % 7)) % 7;
    }
    if(week < 0)
      week += 7;
    printf("%s %d, %d is a %s\n", months[m].c_str(), d, y, weeks[week].c_str());
  }
  return 0;
}
