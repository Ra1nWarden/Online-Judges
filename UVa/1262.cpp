#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int k;
char puzzle[2][10][10];
bool check[26];
bool inset[26];
int chars[6][10];
char ans[10];

int main() {
  int tc;
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d\n", &k);
    for(int i = 0; i < 12; i++) {
      scanf("%s\n", puzzle[i/6][i%6]);
    }
    bool possible = true;
    for(int j = 0; j < 5; j++) {
      memset(check, false, sizeof check);
      for(int i = 0; i < 6; i++) {
	check[puzzle[0][i][j] - 'A'] = true;
      }
      chars[j][0] = 0;
      memset(inset, false, sizeof inset);
      for(int i = 0; i < 6; i++) {
	if(check[puzzle[1][i][j] - 'A'] && !inset[puzzle[1][i][j] - 'A']) {
	  chars[j][++chars[j][0]] = puzzle[1][i][j];
	  inset[puzzle[1][i][j] - 'A'] = true;
	}
      }
      if(chars[j][0] == 0) {
	possible = false;
	break;
      }
      sort(chars[j]+1, chars[j]+chars[j][0]+1);
    }
    if(possible) {
      for(int j = 0; j < 5; j++) {
	int count = 1;
	for(int jj = j + 1; jj < 5; jj++) {
	  count *= chars[jj][0];
	}
	int idx = k / count;
	if(k % count == 0)
	  idx--;
	if(idx >= chars[j][0]) {
	  possible = false;
	  break;
	}
	ans[j] = (char) chars[j][idx + 1];
	k -= idx * count;
      }
      ans[5] = '\0';
    }
    if(possible)
      printf("%s\n", ans);
    else
      printf("NO\n");
  }
  return 0;
}
