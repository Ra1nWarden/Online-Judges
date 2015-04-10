#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 100005
#define MAXL 55

using namespace std;

char names[MAXN][2][MAXL];
int ranks[MAXN];
char prev[MAXL];

int main() {
  int n;
  scanf("%d\n", &n);
  for(int i = 0; i < n; i++)
    scanf("%s %s\n", names[i][0], names[i][1]);
  for(int i = 0; i < n; i++) {
    scanf("%d", &ranks[i]);
    ranks[i]--;
  }
  bool ok = true;
  prev[0] = '\0';
  for(int i = 0; i < n; i++) {
    int index = ranks[i];
    int cmp1 = strcmp(prev, names[index][0]);
    int cmp2 = strcmp(prev, names[index][1]);
    if(cmp1 > 0 && cmp2 > 0) {
      ok = false;
      break;
    } else if(cmp1 < 0 && cmp2 > 0) {
      strcpy(prev, names[index][0]);
    } else if(cmp1 > 0 && cmp2 < 0) {
      strcpy(prev, names[index][1]);
    } else {
      if(strcmp(names[index][0], names[index][1]) < 0) {
	strcpy(prev, names[index][0]);
      } else {
	strcpy(prev, names[index][1]);
      }
    } 
  }
  if(ok)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
