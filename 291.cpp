#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool adjacency[6][6];

void dfs(int current, int sides, string str) {
  str += char('0' + current);
  if (sides == 8) {
    cout << str << endl;
    return;
  }
  for(int i = 1; i <= 5; i++) {
    if (adjacency[current][i]) {
      adjacency[current][i] = false;
      adjacency[i][current] = false;
      dfs(i, sides+1, str);
      adjacency[current][i] = true;
      adjacency[i][current] = true;
    }
  }
}

int main() {
  memset(adjacency, false, sizeof(adjacency));
  for(int i = 1; i <= 5; i++) {
    for(int j= 1; j <= 5; j++) {
      if (i == 4 || j == 4)
	continue;
      if (i != j)
	adjacency[i][j] = true;
    }
  }
  adjacency[4][3] = true;
  adjacency[3][4] = true;
  adjacency[4][5] = true;
  adjacency[5][4] = true;
  dfs(1, 0, "");
  return 0;
}
