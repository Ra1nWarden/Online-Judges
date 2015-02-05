#include <iostream>

using namespace std;

int countDrink(int full, int empty, int orig) {
  int result = orig + full;
  if (full + empty < 3)
    return result;
  result = countDrink((full + empty) / 3, (full + empty) % 3, result);
  return result;
}

int main() {
  int n;
  while(cin >> n) {
    int case1, case2;
    case1 = countDrink(n, 0, 0);
    case2 = countDrink(n, 1, 0);
    cout << (case1 > case2 ? case1 : case2) << endl;
  }
  return 0;
}
