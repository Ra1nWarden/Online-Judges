#include <cstdio>
#include <cstring>

using namespace std;

const int maxl = 9;

char str[maxl+5];
char ans[maxl+5];
int n;

bool dfs(int& i, int& j, int& four, int& seven, bool& large) {
  if(j == n) {
    ans[j] = '\0';
    return true;
  }
  if(large) {
    if(four) {
      ans[j] = '4';
      four--;
    } else {
      ans[j] = '7';
      seven--;
    }
    j++;
    i++;
    return dfs(i, j, four, seven, large);
  } else {
    if(four && str[i] <= '4') {
      ans[j] = '4';
      four--;
      bool lcpy = large;
      large = str[i] < '4';
      i++;
      j++;
      if(dfs(i, j, four, seven, large))
	return true;
      else {
	four++;
	i--;
	j--;
	large = lcpy;
      }
    }
    if(seven && str[i] <= '7') {
      ans[j] = '7';
      seven--;
      bool lcpy = large;
      large = str[i] < '7';
      i++;
      j++;
      if(dfs(i, j, four, seven, large))
	return true;
      else {
	i--;
	j--;
	seven++;
	large = lcpy;
	return false;
      }
    } else {
      return false;
    }
  }
}

bool check_max() {
  for(int i = 0; i < n; i++) {
    if(i < n / 2) {
      if(str[i] > '7')
	return false;
      else if(str[i] < '7')
	return true;
    } else {
      if(str[i] > '4')
	return false;
      else if(str[i] < '4')
	return true;
    }
  }
  return true;
}

int main() {
  scanf("%s", str);
  n = strlen(str);
  int i = 0, j = 0;
  int four = (n + 1) / 2, seven = (n + 1) / 2;
  bool large = false;
  if(n % 2) {
    n++;
    ans[j++] = '4';
    four--;
    large = true;
  } else if(!check_max()) {
    n += 2;
    ans[j] = ans[j+1] = '4';
    j += 2;
    four--;
    seven++;
    large = true;
  }
  dfs(i, j, four, seven, large);
  printf("%s\n", ans);
  return 0;
}
