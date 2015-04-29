#include <bits/stdc++.h>
#define MAXN 70
#define MAXL 5000

using namespace std;

bool getch() {
  char ch;
  while(scanf("%c", &ch)) {
    if(ch == '0' || ch == '1')
      break;
  }
  return ch == '1';
}

bool board[MAXN][MAXN];
int n;
int v[MAXL];
int vi;
int kase;

bool check_block(int x, int y, int w) {
  for(int i = x; i < x + w; i++) {
    for(int j = y; j < y + w; j++) {
      if(!board[i][j])
	return false;
    }
  }
  return true;
}

void encode_helper(int x, int y, int w, int base, int level, vector<int>& codes) {
  if(check_block(x, y, w)) {
    codes.push_back(base);
  } else {
    int ww = w / 2;
    if(ww > 0) {
      encode_helper(x, y, ww, base + 1 * level, level * 5, codes);
      encode_helper(x, y + ww, ww, base + 2 * level, level * 5, codes);
      encode_helper(x + ww, y, ww, base + 3 * level, level * 5, codes);
      encode_helper(x + ww, y + ww, ww, base + 4 * level, level * 5, codes);
    }
  }
}

void encode() {
  vector<int> codes;
  encode_helper(0, 0, n, 0, 1, codes);
  sort(codes.begin(), codes.end());
  printf("Image %d\n", kase++);
  for(int i = 0; i < codes.size(); i++) {
    if(i > 0 && i % 12 == 0)
      printf("\n");
    else if(i > 0)
      printf(" ");
    printf("%d",  codes[i]);
  }
  if(codes.size() > 0)
    printf("\n");
  printf("Total number of black nodes = %d\n", codes.size());
}

void fill_board(int x, int y, int w) {
  for(int i = x; i < x + w; i++) {
    for(int j = y; j < y + w; j++) {
      board[i][j] = true;
    }
  }
}

void decode() {
  for(int i= 0; i < vi; i++) {
    int code = v[i];
    int w = -n;
    int x = 0;
    int y = 0;
    while(code > 0) {
      int dir = code % 5;
      switch(dir) {
      case 1:
	w /= 2;
	break;
      case 2:
	w /= 2;
	y += w;
	break;
      case 3:
	w /= 2;
	x += w;
	break;
      case 4:
	w /= 2;
	x += w;
	y += w;
	break;
      }
      code /= 5;
    }
    fill_board(x, y, w);
  }
  printf("Image %d\n", kase++);
  for(int i = 0; i < -n; i++) {
    for(int j = 0; j < -n; j++) {
      if(board[i][j])
	printf("*");
      else
	printf(".");
    }
    printf("\n");
  }
}

int main() {
  kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    memset(board, false, sizeof board);
    if(kase > 1)
      printf("\n");
    if(n > 0) {
      for(int i = 0; i < n; i++) {
	for(int j = 0; j < n; j++) {
	  board[i][j] = getch();
	}
      }
      encode();
    } else {
      vi = 0;
      int code;
      while(scanf("%d", &code) != EOF && code >= 0) {
	v[vi++] = code;
      }
      decode();
    }
  }
  return 0;
}
