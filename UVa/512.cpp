#include <cstdio>
#include <vector>
#define MAXN 15

using namespace std;

int r, c;

struct Operation {
  char op[5];
  int vn;
  int v[MAXN];
  int ex[4];
};

vector<Operation> ops;

int main() {						
  int kase = 1;
  while(scanf("%d %d", &r, &c) != EOF && (r || c)) {
    if(kase > 1)
      printf("\n");
    int n;
    scanf("%d\n", &n);
    ops.clear();
    for(int i = 0; i < n; i++) {
      Operation add;
      scanf("%c%c", &add.op[0], &add.op[1]);
      if(add.op[0] == 'E' && add.op[1] == 'X') {
	scanf("%d %d %d %d\n", &add.ex[0], &add.ex[1],&add.ex[2],&add.ex[3]);
      } else {
	scanf("%d", &add.vn);
	for(int j = 0; j < add.vn; j++)
	  scanf("%d", &add.v[j]);
	scanf("\n");
      }
      ops.push_back(add);
    }
    int qn;
    scanf("%d", &qn);
    printf("Spreadsheet #%d\n", kase++);
    for(int i = 0; i < qn; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      bool gone = false;
      int origx = x;
      int origy = y;
      for(int j = 0; j < ops.size(); j++) {
	Operation next = ops[j];
	if(next.op[0] == 'E' && next.op[1] == 'X') {
	  if(next.ex[0] == x && next.ex[1] == y) {
	    x = next.ex[2];
	    y = next.ex[3];
	  } else if(next.ex[2] == x && next.ex[3] == y) {
	    x = next.ex[0];
	    y = next.ex[1];
	  }
	} else if(next.op[0] == 'D' && next.op[1] == 'R') {
	  int del = 0;
	  for(int k = 0; k < next.vn; k++) {
	    if(next.v[k] == x) {
	      gone = true;
	      break;
	    }
	    if(next.v[k] < x)
	      del++;
	  }
	  x -= del;
	} else if(next.op[0] == 'D' && next.op[1] == 'C') {
	  int del = 0;
	  for(int k = 0; k < next.vn; k++) {
	    if(next.v[k] == y) {
	      gone = true;
	      break;
	    }
	    if(next.v[k] < y)
	      del++;
	  }
	  y -= del;
	} else if(next.op[0] == 'I' && next.op[1] == 'R') {
	  int add = 0;
	  for(int k = 0; k < next.vn; k++) {
	    if(next.v[k] <= x) {
	      add++;
	    }
	  }
	  x += add;
	} else if(next.op[0] == 'I' && next.op[1] == 'C') {
	  int add = 0;
	  for(int k = 0; k < next.vn; k++) {
	    if(next.v[k] <= y) {
	      add++;
	    }
	  }
	  y += add;
	}
	if(gone)
	  break;
      }
      if(gone)
	printf("Cell data in (%d,%d) GONE\n", origx, origy);
      else
	printf("Cell data in (%d,%d) moved to (%d,%d)\n", origx, origy, x, y);
    }
  }
  return 0;
}
