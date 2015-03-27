#include <iostream>

using namespace std;

static int v[] = {2, 7, 2, 3, 3, 4, 2, 5, 1, 2};

int main() {
  int n;
  cin >> n;
  int x = n % 10;
  int y = n / 10;
  cout << v[x] * v[y] << endl;
  return 0;
}
