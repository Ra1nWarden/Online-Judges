#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int trans[6][12][2] = {
  {{1, 2}, {2, 4}, {4, 3}, {3, 1}, {5, 13}, {6, 14}, {17, 5}, {18, 6}, {21, 17}, {22, 18}, {13, 21}, {14, 21}}, // top
  {{9, 10}, {10, 12},  {12, 11}, {11, 9}, {7, 19}, {8, 20}, {19, 23}, {20, 24}, {23, 15}, {24, 16}, {15, 7}, {16, 8}}, // btm
  {{5, 9}, {7, 11}, {9, 24}, {11, 22}, {24, 1}, {22, 3}, {1, 5}, {3, 7}, {13, 14}, {14, 16}, {16, 15}, {15, 13}}, // left
  {{6, 10}, {8, 12}, {10, 23}, {12, 21}, {23, 2}, {21, 4}, {2, 6}, {4, 8}, {17, 19}, {19, 20}, {20, 18}, {18, 17}}, // right
  {{5, 6}, {6, 8}, {8, 7}, {7, 5}, {3, 17}, {4, 19}, {17, 10}, {19, 9}, {10, 16}, {9, 14}, {16, 3}, {14, 4}}, // front
  {{21, 22}, {22, 24}, {24, 23}, {23, 21}, {2, 13}, {1, 15}, {13, 11}, {15, 12}, {11, 20}, {12, 18}, {20, 2}, {18, 1}} // back
};

const int size = 24;
int mat[size];
int nxt[size];

bool check(int* arr) {
  for(int i = 0; i < size / 6; i++) {
    for(int j = 0; j < 4; j++) {
      if(arr[i * 4 + j] != arr[i * 4])
	return false;
    }
  }
  return true;
}

int main() {
  for(int i = 0; i < size; i++)
    scanf("%d", &mat[i]);
  bool ok = false;
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 2; j++) {
      memcpy(nxt, mat, sizeof nxt);
      for(int k = 0; k < 12; k++) {
	nxt[trans[i][k][j] - 1] = mat[trans[i][k][(j+1) % 2] - 1];
      }
      if(check(nxt)) {
	ok = true;
	break;
      }
    }
    if(ok)
      break;
  }
  printf(ok ? "YES\n" : "NO\n");
  return 0;
}
