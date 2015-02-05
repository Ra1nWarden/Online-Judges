#include <iostream>
#include <cstring>
#include <climits>
#include <iomanip>
#define EPSILON 1e-8

using namespace std;

int coins[] = {0, 1, 2, 4, 10, 20, 40};
int dmemo[7][2501];
int v[7];
int memo[2501][7][2501];

void init() {
  memset(dmemo, -1, sizeof dmemo);
  for(int i= 0; i <= 6; i++) {
    for(int j = 0; j <= 2500; j++) {
      if(j == 0)
	dmemo[i][j] = 0;
      else if(i == 0)
	dmemo[i][j] = -1;
      else if (j >= coins[i]) {
	int first = dmemo[i][j-coins[i]];
	int second = dmemo[i-1][j];
	if(first == -1)
	  dmemo[i][j] = second;
	if(second == -1)
	  dmemo[i][j] = first+1;
	else
	  dmemo[i][j] = min(first+1, second);
      } else {
	dmemo[i][j] = dmemo[i-1][j];
      }
    }
  }
}

// i = amount we want to make
// j = first j coins
// k = limit on jth coin
int g(int i, int j, int k) {
  if(memo[i][j][k] > -2)
    return memo[i][j][k];
  int result = -1;
  if(i == 0)
    result = 0;
  else if(j == 0)
    result = -1;
  else if(k == 0)
    result = g(i, j-1, v[j-1]);
  else if(i >= coins[j]) {
    int first = g(i - coins[j], j, k-1);
    int second = g(i, j-1, v[j-1]);
    if(first == -1)
      result = second;
    else if(second == -1)
      result = first+1;
    else
      result = min(first+1, second);
  }
  else
    result = g(i, j-1, v[j-1]);
  memo[i][j][k] = result;
  return result;
}

int main() {
  init();
  int a, b, c, d, e, f;
  while(cin >> a >> b >> c >> d >> e >> f && (a || b || c || d || e || f)) {
    memset(memo, -2, sizeof memo);
    double money;
    cin >> money;
    int n = (int) ((money+EPSILON) * 20);
    int vc[] = {0, a, b, c, d, e, f};
    memcpy(v, vc, sizeof v);
    int result = g(n, 6, v[6]);
    if(result < 0)
      result = INT_MAX;
    for(int x = n+1 ; x <= a + b*2 + 4*c + 10 * d + 20* e + 40 * f; x++) {
      int next = g(x, 6, v[6]);
      if(next > 0) {
	result = min(result, next + dmemo[6][x - n]);
      }
    }
    cout << setw(3) << result << endl;
  }
  return 0;
}
