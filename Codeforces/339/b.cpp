#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  string line;
  getline(cin, line);
  stringstream nss(line.c_str());
  int n;
  nss >> n;
  getline(cin, line);
  stringstream ss(line.c_str());
  string fact = "1";
  bool found = false;
  bool zero = false;
  int len = 0;
  while(n--) {
    string number;
    ss >> number;
    if(number[0] == '0') {
      zero = true;
      break;
    }
    if(found) {
      len += number.length() - 1;
      continue;
    }
    bool ok = true;
    bool one = true;
    for(int i = 0; i < number.size(); i++) {
      if(number[i] == '1') {
	if(!one) {
	  ok = false;
	  break;
	} else {
	  one = false;
	}
      } else if(number[i] != '0') {
	ok = false;
	break;
      }
    }
    if(!ok) {
      found = true;
      fact = number;
    } else {
      len += number.length() - 1;
    }
  }
  if(zero) {
    cout << 0 << endl;
  } else {
    stringstream ans;
    ans << fact;
    string zeros(len, '0');
    ans << zeros;
    cout << ans.str() << endl;
  }
  return 0;
}
