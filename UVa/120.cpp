#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream>
#include <string>
#define MAXN 35

using namespace std;

int v[MAXN], vi;
int ans[2*MAXN], ai;

bool is_sorted() {
  for(int i = 0; i < vi - 1; i++) {
    if(v[i] > v[i+1])
      return false;
  }
  return true;
}

void flip(int n) {
  if(n == 0)
    return;
  reverse(v, v+n+1);
  ans[ai++] = vi-n;
}

int main() {
  ios::sync_with_stdio(false);
  string line;
  while(getline(cin, line)) {
    stringstream ss(line.c_str());
    vi = 0;
    int number;
    while(ss >> number) {
      v[vi++] = number;
    }
    for(int i = 0; i < vi; i++) {
      if(i > 0)
	printf(" ");
      printf("%d", v[i]);
    }
    printf("\n");
    ai = 0;
    int ti = 0;
    for(int i = vi - 1; i > 0; i--) {
      int p = max_element(v, v+i+1) - v;
      if(p != i) {
	if(p > 0)
	  flip(p);
	flip(i);
      }
    }
    ans[ai++] = 0;
    for(int i = 0; i < ai; i++) {
      if(i > 0)
	printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
