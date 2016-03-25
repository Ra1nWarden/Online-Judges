#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

const int maxl = 40000;
char str[maxl+5];
int l, m;
const unsigned long long x = 123;
unsigned long long h[maxl+5];
unsigned long long powers[maxl+5];
map<unsigned long long, int> count;

void init() {
  h[l] = 0;
  for(int i = l - 1; i >= 0; i--) {
    h[i] = h[i + 1] * x + (str[i] - 'a');
  }
  powers[0] = 1;
  for(int i = 1; i <= l; i++) {
    powers[i] = powers[i - 1] * x;
  }
}

unsigned long long f(int i, int len) {
  return h[i] - h[i + len] * powers[len];
}

int main() {
  while(scanf("%d\n", &m) != EOF && m) {
    scanf("%s\n", str);
    l = strlen(str);
    init();
    int left = 0, right = l - m + 1;
    while(left != right) {
      bool ok = false;
      count.clear();
      int mid = (left + right) / 2 + 1;
      for(int i = 0; i + mid <= l; i++) {
	unsigned long long sub_hash = f(i, mid);
	if(count.count(sub_hash) == 0) {
	  count[sub_hash] = 0;
	} 
	int cnt = ++count[sub_hash];
	if(cnt >= m) {
	  ok = true;
	  break;
	}
      }
      if(!ok) {
	right = mid - 1;
      } else {
	left = mid;
      }
    }
    if(left == 0) {
      printf("none\n");
    } else {
      int start = -1;
      count.clear();
      for(int i = 0; i + left <= l; i++) {
	unsigned long long sub_hash = f(i, left);
	if(count.count(sub_hash) == 0) {
	  count[sub_hash] = 0;
	}
	int cnt = ++count[sub_hash];
	if(cnt >= m) {
	  start = i;
	}
      }
      printf("%d %d\n", left, start);
    }
  }
  return 0;
}
