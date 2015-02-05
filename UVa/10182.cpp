#include <iostream>

using namespace std;

int main() {
  int number;
  while (cin >> number) {
    number = number - 1;
    int round = 0;
    if (number > 0) {
      for (int i = 1; i > 0; i++) {
	int sub = i * 6;
	if (sub > number) {
	  round = i - 1;
	  break;
	}
	else {
	  number -= sub;
	}
      }
    }
    int x = round;
    int y = 0;
    while (number > 0) {
      if (x >= 0 && y == 0) {
	y += 1;
	number--;
	continue;
      }
      else if (x > 0 && y > 0) {
	x -= 1;
	y += 1;
	number--;
	continue;
      }
      else if (x == 0 && y > 0) {
	x -= 1;
	number--;
	continue;
      }
      else if (x < 0 && y > 0 && -x < y) {
	x -= 1;
	number--;
	continue;
      }
      else if (x < 0 && y > 0 && x == -y) {
	y -= 1;
	number--;
	continue;
      }
      else if (x < 0 && y > 0 && -x > y) {
	y -= 1;
	number--;
	continue;
      }
      else if (x < 0 && y == 0) {
	x += 1;
	y -= 1;
	number--;
	continue;
      } 
      else if (x < 0 && y < 0) {
	x += 1;
	y -= 1;
	number--;
	continue;
      }
      else if (x == 0 && y < 0) {
	x += 1;
	number--;
	continue;
      }
      else if (x > 0 && y < 0 && x < -y) {
	x += 1;
	number--;
	continue;
      }
      else if (x > 0 && y < 0 && x == -y) {
	y += 1;
	number--;
	continue;
      }
      else if (x > 0 && y < 0 && x > -y) {
	y += 1;
	number--;
	continue;
      }
    }
    cout << x << " " << y << endl;
  }
  return 0;
}
