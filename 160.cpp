#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <iomanip>

using namespace std;

int prime[25];
int result[101][25];

int main() {
  int primeindex = 0;
  bool slots[101];
  memset(slots, true, sizeof slots);
  for(int i = 2; i < 101; i++) {
    if(slots[i]) {
      prime[primeindex++] = i;
      for(int j = i + i; j < 101; j += i) {
	slots[j] = false;
      }
    }
  }
  memset(result, 0, sizeof result);
  result[2][0] = 1;
  for(int i = 3; i < 101; i++) {
    memcpy(result[i], result[i-1], sizeof result[i-1]);
    for(int j = 0; j < 25; j++) {
      int icopy = i;
      if(icopy % prime[j] == 0) {
	int count = 0;
	while(icopy % prime[j] == 0) {
	  icopy /= prime[j];
	  count++;
	}
	result[i][j] += count;
      }
    }
  }

  int x;
  while(cin >> x && x) {
    printf("%3d! = ", x);
    vector<int> printv;
    bool startp = false;
    for(int i = 24; i >= 0; i--) {
      if(result[x][i] != 0)
	startp = true;
      if(startp)
	printv.push_back(result[x][i]);
    }
    for(int i = printv.size() - 1; i>= 0; i--) {
      if(printv.size() - i == 16)
	cout << endl << "      ";
      if(i != printv.size() - 1)
	cout << " ";
      cout << right << setw(2) << printv[i];
    }
    cout << endl;
  }
  return 0;
}
