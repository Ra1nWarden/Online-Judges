#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long sum = a + b + c + d;
    sum *= 2;
    if(sum % 3 == 0 || sum % 4 == 0) {
      cout << "Yes" << endl;
      continue;
    }
    cout << "No" << endl;
  }
  return 0;
}
