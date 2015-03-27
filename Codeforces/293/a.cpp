#include <iostream>

using namespace std;

int main() {
  string a, b;
  getline(cin, a);
  getline(cin, b);
  bool add = true;
  for(int i = a.length() - 1; i > -1 && add; i--) {
    if(a[i] == 'z') {
      a[i] = 'a';
    } else {
      a[i] = a[i]+ 1;
      add = false;
    }
  }
  if(add || (!add && a == b))
    cout << "No such string" << endl;
  else
    cout << a << endl;
  return 0;
}
