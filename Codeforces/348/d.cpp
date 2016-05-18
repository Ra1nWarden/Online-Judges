#include <cstdio>

using namespace std;

void normalize(int& num, int mod) {
  while(num < 0) {
    num += mod;
  }
  num %= mod;
}

int main() {
  int odd = 0;
  int even = 0;
  int start = 1;
  int n, q;
  scanf("%d%d", &n, &q);
  while(q--) {
    int op;
    scanf("%d", &op);
    if(op == 1) {
      int delta;
      scanf("%d", &delta);
      bool clock = delta >= 0;
      if(!clock) {
	delta = -delta;
      }
      if(start == 0) {
	if(!clock) {
	  even += (delta + 1) / 2;
	  odd += delta / 2;
	} else {
	  odd -= (delta + 1) / 2;
	  even -= delta / 2;
	}
      } else {
	if(!clock) {
	  odd += (delta + 1) / 2;
	  even += delta / 2;
	} else {
	  even -= (delta + 1) / 2;
	  odd -= delta / 2;
	}
      }
      normalize(odd, n / 2);
      normalize(even,  n / 2);
      if(delta % 2 == 1) {
	start = !start;
      }
    } else if(op == 2) {
      start = !start;
    }
  }
  int odd_num = 1 + odd * 2;
  int even_num = 2 + even * 2;
  for(int i = 0; i < n; i++) {
    if(i)
      printf(" ");
    if(start == 1) {
      printf("%d", odd_num);
      odd_num += 2;
      if(odd_num > n)
	odd_num = 1;
    } else {
      printf("%d", even_num);
      even_num += 2;
      if(even_num > n)
	even_num = 2;
    }
    start = !start;
  }
  printf("\n");
  return 0;
}
