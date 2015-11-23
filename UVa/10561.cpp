#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxl = 200;
char str[maxl+5];
int sg[maxl+5];
bool visited[maxl+5];
int n;

int init() {
  sg[0] = 0;
  sg[1] = sg[2] = 1;
  for(int len = 3; len <= maxl; len++) {
    memset(visited, false, sizeof visited);
    for(int j = 0; j < len; j++) {
      int left = max(0, j - 2);
      int right = max(0, len - j - 3);
      visited[sg[left] ^ sg[right]] = true;
    }
    for(int j = 0; j <= maxl; j++) {
      if(!visited[j]) {
	sg[len] = j;
	break;
      }
    }
  }
}

bool legal(int i) {
  if(str[i] == 'X')
    return false;
  if(i - 1 > -1 && str[i-1] == 'X')
    return false;
  if(i - 2 > -1 && str[i-2] == 'X')
    return false;
  if(i + 1 < n && str[i+1] == 'X')
    return false;
  if(i + 2 < n && str[i+2] == 'X')
    return false;
  return true;
}

int main() {
  init();
  int tc;
  scanf("%d\n", &tc);
  while(tc--) {
    scanf("%s\n", str);
    n = strlen(str);
    vector<int> ans;
    int prev = -5;
    for(int i = 0; i < n; i++) {
      if(str[i] == 'X') {
	int diff = i - prev;
	if(diff == 1) {
	  int a = i - 2;
	  if(a > -1 && str[a] != 'X' && (ans.empty() || ans.back() != a))
	    ans.push_back(a+1);
	  a = i + 1;
	  if(a < n && str[a] != 'X')
	    ans.push_back(a+1);
	}
	else if(diff == 2) {
	  int a = i - 1;
	  if(str[a] != 'X' && (ans.empty() || ans.back() != a))
	    ans.push_back(a+1);
	}
	prev = i;
      }
    }
    if(ans.empty()) {
      for(int i = 0; i < n; i++) {
	if(!legal(i))
	  continue;
	str[i] = 'X';
	int nim = 0;
	int cnt = 0;
	for(int j = 0; j < n; j++) {
	  if(str[j] == '.') {
	    cnt++;
	  } else {
	    cnt -= 2;
	    if(cnt > 0) {
	      nim ^= sg[cnt];
	    }
	    cnt = -2;
	  }
	}
	if(cnt > 0)
	  nim ^= sg[cnt];
	str[i] = '.';
	if(nim == 0) {
	  ans.push_back(i+1);
	}
      }
    }
    if(ans.empty()) {
      printf("LOSING\n\n");
    } else {
      printf("WINNING\n");
      for(int i = 0; i < ans.size(); i++) {
	if(i > 0)
	  printf(" ");
	printf("%d", ans[i]);
      }
      printf("\n");
    }
  }
  return 0;
}
