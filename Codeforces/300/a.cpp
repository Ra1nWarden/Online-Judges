#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXL 105

using namespace std;

char buff[MAXL];
char check[] = "CODEFORCES";

bool solve(int ci, int bi, bool extra, bool match_mode) {
  if(bi == strlen(buff))
    return ci == 10;
  if(check[ci] == buff[bi]) {
    if(match_mode) {
      if(extra)
	return solve(ci+1, bi+1, true, true) || solve(ci, bi+1, false, false);
      else
	return solve(ci+1, bi+1, false, true);
    } else {
      return solve(ci+1, bi+1, extra, true) || solve(ci, bi+1, false, match_mode);
    }
  } else {
    if(match_mode) {
      if(extra)
	return solve(ci, bi+1, false, false);
      else
	return false;
    } else {
      return solve(ci, bi+1, false, false);
    }
  }
}

int main() {
  scanf("%s", buff);
  int n = strlen(buff);
  bool ans = solve(0, 0, true, false);
  if(ans)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
