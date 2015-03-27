#include <iostream>

using namespace std;

bool good(int v[], int len) {
  int oddsum = 0;
  int evensum = 0;
  for(int i = 0; i < len; i++) {
    if(i % 2 == 0)
      evensum += v[i];
    else
      oddsum += v[i]; 
  }
  if(evensum != oddsum)
    return false;
  bool pali = true;
  for(int i = 0; i < len/2; i++) {
    if(v[i] != v[len - i - 1]) {
      pali = false;
      break;
    }
  }
  return !pali;
}

int main() {
  int tc;
  cin >> tc;
  for(int i = 0; i < tc; i++) {
    int n;
    cin >> n;
    int v[n];
    for(int j = 0; j < n; j++) {
      int x;
      cin >> x;
      v[j] = x;
    }
    cout << (good(v, n) ? "Yes" : "No") << endl;
  }
  return 0;
}
