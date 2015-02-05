#include <iostream>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int n, m;
    cin >> n >> m;
    int x, y;
    x = (n - 2) / 3;
    if ((n - 2) % 3 != 0)
      x++;
    y = (m - 2) / 3;
    if ((m - 2) % 3 != 0)
      y++;
    cout << x*y << endl;
  }
  return 0;
}
