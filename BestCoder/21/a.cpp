#include <iostream>

using namespace std;

const int v[] =  {15, 7, 4, 2, 1};

int main() {
  int x;
  while(cin >> x) {
    bool start = true;
    for(int i = 0; i < 5; i++) {
      if(x - v[i] > 0) {
	if(start) {
	  cout << x - v[i];
	  start = false;
	} else {
	  cout << " " << x - v[i];
	}
      }
    }
    cout << endl;
  }
  return 0;
}
