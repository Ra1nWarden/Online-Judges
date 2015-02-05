#include <iostream>
#include <cmath>

using namespace std;

int main() {
  while(true) {
    long x, y;
    long number;
    cin >> number;
    if(number == 0)
      break;
    long root = (long) sqrt(number);
    long sqred = root * root;
    long diff = number - sqred;
    long maxside = root + 1;
    if(root % 2 == 0) {
      if(diff == 0) {
	x = root;
	y = 1;
      }
      else if(diff <= maxside) {
	x = root + 1;
	y = diff;
      }
      else {
	y = root + 1;
	x = root + 1 - (diff - maxside);
      }
    }
    else {
      if(diff == 0) {
	y = root;
	x = 1;
      }
      else if(diff <= maxside) {
	y = root + 1;
	x = diff;
      }
      else {
	x = root + 1;
	y = root + 1 - (diff - maxside);
      }
    }
    cout << x << " " << y << endl;
  }
  return 0;
}
