#include <iostream>
#include <cstring>

using namespace std;

bool test[100001];

int main() {
  int a, m;
  cin >> a >> m;
  
  memset(test, false, sizeof test);
  
  test[a] = true;

  while(true) {
    a = (2*a % m);
    if(test[a])
      break;
    else
      test[a] = true;
  }
  
  cout << (test[0] ? "Yes" : "No") << endl; 

  return 0;
}
