#include <iostream>
#include <algorithm>
#define MAXN 100

using namespace std;

int num[MAXN];
int numi;

bool _cmp(int a, int b) {
  return a > b;
}

int main() {
  int n;
  cin >> n;
  numi = 0;
  string str;
  getline(cin, str);
  getline(cin, str);
  for(int i = 0; i < n; i++) {
    if(str[i] == '0' || str[i] == '1')
      continue;
    num[numi++] = str[i] - '0';
  }
  sort(num, num + numi, _cmp);
  for(int i = numi - 1; i >= 0; i--) {
    if(num[i] == 4) {
      num[numi++] = 2;
      num[numi++] = 2;
      num[i] = 3;
    } else if(num[i] == 6) {
      num[numi++] = 3;
      num[i] = 5;
    } else if(num[i] == 8) {
      num[numi++] = 2;
      num[numi++] = 2;
      num[numi++] = 2;
      num[i] = 7;
    } else if(num[i] == 9) {
      num[numi++] = 3;
      num[numi++] = 3;
      num[numi++] = 2;
      num[i] = 7;
    }
  }
  sort(num, num + numi, _cmp);
  for(int i = 0; i < numi; i++)
    cout << num[i];
  cout << endl;
  return 0;
}
