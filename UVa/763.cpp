#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int x[200];

int main() {
  string a, b;
  bool init = true;
  while(getline(cin, a) && getline(cin, b)) {
    if(!init)
      cout << endl;
    memset(x, 0, sizeof x);
    for(int i = 0; i < a.length(); i++) {
      x[i] += atoi(a.substr(a.length() - 1 - i, 1).c_str());
    }
    for(int i = 0; i < b.length(); i++) {
      x[i] += atoi(b.substr(b.length() - 1 - i, 1).c_str());
    }

    // cout << "printing sum" << endl;
    // for(int i = 0; i < max(a.length(), b.length()); i++)
    //   cout << x[i];
    // cout << endl;

    bool zero = true;
    for(int i = 0; i < 200; i++) {
      if(x[i] != 0)
	zero = false;
    }

    if(zero) {
      cout << 0 << endl;
    } else {
      while(true) {
	bool twocheck = false;
	for(int i = 0; i < 200; i++) {
	  if(x[i] > 1) {
	    if(i == 0) {
	      x[0] -= 2;
	      x[1] += 1;
	    } else if (i == 1) {
	      x[1] -= 2;
	      x[2] += 1;
	      x[0] += 1;
	    } else {
	      x[i] -= 2;
	      x[i+1] += 1;
	      x[i-2] += 1;
	    }
	    twocheck = true;
	  }
	}
	if(!twocheck) {
	  bool prop = false;
	  for(int i = 0; i < 198; i++) {
	    if(x[i] > 0 && x[i+1] > 0) {
	      prop = true;
	      x[i+2]++;
	      x[i]--;
	      x[i+1]--;
	    }
	  }
	  if(!prop)
	    break;
	}
      }

      
      
      string result(200, '0');
      int prev = -1;
      for(int i = 0; i < 200; i++) {
	if(x[199 - i] == 1) {
	  if(prev == -1)
	    prev = i;
	  result[i] = '1';
	}
      }
      
      // cout << "result is " << result << endl;
      // cout << "prev is " << prev << endl;
      // cout << "after printing sum" << endl;
      // for(int i = 0; i < 200; i++)
      //   cout << x[i];
      // cout << endl;
      
      cout << result.substr(prev) << endl;
    }
    init = false;
    getline(cin, a);
  }
  return 0;
}
