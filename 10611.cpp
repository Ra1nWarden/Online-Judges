#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

void findResult(int* array, int a, int b, int target) {
  int* first = lower_bound(array+a, array+b, target);
  if (first == array) {
    cout << "X ";
  } else if (first == array + b) {
    if (*(--first) < target)
      cout << *(first) << " ";
  } else {
    cout << *(--first) << " ";
  }
  int* second = upper_bound(array+a, array+b, target);
  if (second == array+b) {
    cout << "X" << endl;
  } else {
    cout << *second << endl;
  }
}

int main() {
  int l;
  cin >> l;
  int n[l];
  memset(n, 0, l);
  for (int i = 0; i < l; i++) {
    int x;
    cin >> x;
    n[i] = x;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int y;
    cin >> y;
    findResult(n, 0, l, y);
  }
  return 0;
}
