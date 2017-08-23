#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

string v[] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
int mat[8][2] = {{0, 1}, {2, 3}, {4, 5}, {6, 7}, {0, 1}, {2, 3}, {4, 5}, {6, 7}};
const int maxn = 40;
char str[maxn+5];
int tc;
int ans[8];

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d\n", &tc);
    scanf("%s", str);
    memset(ans, 0, sizeof ans);
    string s = "";
    for(int j = 0; j < 3; j++)
      s += str[j];
    int cur;
    for(int j = 0; j < 8; j++) {
      if(v[j] == s) {
	cur = j;
	break;
      }
    }
    ans[cur]++;
    for(int j = 3; j < 40; j++) {
      if(str[j] == 'T') {
	cur = mat[cur][0];
      } else {
	cur = mat[cur][1];
      }
      ans[cur]++;
    }
    printf("%d", tc);
    for(int i = 0; i < 8; i++)
      printf(" %d", ans[i]);
    printf("\n");
  }
  return 0;
}
