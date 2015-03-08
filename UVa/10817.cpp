#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXM 10
#define MAXN 105
#define INF 2e9

using namespace std;

int s, m, n;
int v[MAXM];
int cost[MAXN][2];
int dp[MAXN][6600];
bool dpv[MAXN][6600];

int f(int first, int bitmask) {
  if(dpv[first][bitmask])
    return dp[first][bitmask];
  if(bitmask == 0) {
    dpv[first][bitmask] = true;
    return dp[first][bitmask] = 0;
  } else if(first == 0) {
    dpv[first][bitmask] = true;
    return dp[first][bitmask] = INF;
  }
  int vcpy[MAXM];
  int maskcpy = bitmask;
  for(int i = 0; i < s; i++) {
    vcpy[i] = (maskcpy % 3);
    maskcpy /= 3;
  }
  for(int i = 0; i < s; i++) {
    if(((1 << i) & cost[first - 1][1]) != 0 && vcpy[i] > 0)
      vcpy[i]--;
  }
  int newmask = 0;
  for(int i = 0; i < s; i++)
    newmask += (pow(3, i) * vcpy[i]);
  dpv[first][bitmask] = true;
  return dp[first][bitmask] = min(f(first - 1, bitmask), f(first - 1, newmask) + cost[first - 1][0]);
}

int main() {
  string line;
  while(cin >> s >> m >> n && (s || m || n)) {
    getline(cin, line);
    int totalcost = 0;
    for(int i = 0; i < s; i++)
      v[i] = 2;
    for(int i = 0; i < m; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      int c;
      iss >> c;
      totalcost += c;
      int sub;
      while(iss >> sub) {
	if(v[sub-1] > 0)
	  v[sub-1]--;
      }
    }
    for(int i = 0; i < n; i++) {
      getline(cin, line);
      istringstream iss(line.c_str());
      iss >> cost[i][0];
      int teach = 0;
      int sub;
      while(iss >> sub)
	teach |= (1 << (sub - 1));
      cost[i][1] = teach;
    }
    int bitmask = 0;
    for(int i = 0; i < s; i++)
      bitmask += (pow(3, i) * v[i]);
    memset(dpv, false, sizeof dpv);
    printf("%d\n", f(n, bitmask) + totalcost);
  }
  return 0;
}
