#include <bits/stdc++.h>

using namespace std;

map<int, int> fm;
map<int, int> bm;

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    fm[a] = b;
    bm[b] = a;
  }
  int v[n];
  int i = 1;
  int num = 0;
  while(i < n) {
    v[i] = fm[num];
    num = v[i];
    i += 2;
  }
  if(n % 2 == 0) {
    i = n - 2;
    num = 0;
    while(i > -1) {
      v[i] = bm[num];
      num = v[i];
      i -= 2;
    }
  } else {
    i = 0;
    for(map<int, int>::iterator itr = fm.begin(); itr != fm.end(); itr++) {
      if(bm.count(itr->first) == 0) {
	num = itr->first;
	break;
      }
    }
    while(i < n) {
      v[i] = num;
      num = fm[num];
      i += 2;
    }
  }
  for(int i = 0; i < n; i++) {
    if(i > 0)
      printf(" ");
    printf("%d", v[i]);
  }
  printf("\n");
  return 0;
}
