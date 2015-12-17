#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const double eps = 1e-8;
const int maxn = 100;
typedef double Matrix[maxn+5][maxn+5];
Matrix mat;
int n;
vector<int> in_nodes[maxn+5];
int out_degree[maxn+5];
bool inf[maxn+5];

void gauss_jordan() {
  int i, j, k, r;
  for(i = 0; i < n; i++) {
    r = i;
    for(j = i + 1; j < n; j++) {
      if(fabs(mat[j][i]) > fabs(mat[r][i])) {
	r = j;
      }
    }
    if(fabs(mat[r][i]) < eps)
      continue;
    if(r != i) {
      for(j = 0; j <= n; j++)
	swap(mat[r][j], mat[i][j]);
    }
    for(k = 0; k < n; k++) {
      if(k != i) {
	for(j = n; j >= i; j--) {
	  mat[k][j] -= mat[k][i] / mat[i][i] * mat[i][j];
	}
      }
    }
  }
}

int main() {
  int kase = 1;
  while(scanf("%d", &n) != EOF && n) {
    n++;
    for(int i = 0; i < n; i++) {
      in_nodes[i].clear();
    }
    memset(out_degree, 0, sizeof out_degree);
    out_degree[0] = 1;
    in_nodes[1].push_back(0);
    int u, v;
    while(scanf("%d%d", &u, &v) != EOF && (u || v)) {
      in_nodes[v].push_back(u);
      out_degree[u]++;
    }
    memset(mat, 0, sizeof mat);
    mat[0][0] = 1;
    mat[0][n] = 1;
    for(int i = 1; i < n; i++) {
      mat[i][i] = 1;
      for(int j = 0; j < in_nodes[i].size(); j++) {
	mat[i][in_nodes[i][j]] = -1.0 / out_degree[in_nodes[i][j]];
      }
    }
    gauss_jordan();
    memset(inf, false, sizeof inf);
    for(int i = n - 1; i >= 0; i--) {
      if(fabs(mat[i][i]) < eps && fabs(mat[i][n]) > eps) {
	inf[i] = true;
      }
      for(int j = i + 1; j < n; j++) {
	if(fabs(mat[i][j]) > eps && inf[j])
	  inf[i] = true;
      }
    }
    int q;
    printf("Case #%d:\n", kase++);
    scanf("%d", &q);
    while(q--) {
      int each;
      scanf("%d", &each);
      if(inf[each]) {
	printf("infinity\n");
      } else if(fabs(mat[each][each]) < eps) {
	printf("0.000\n");
      } else {
	printf("%.3lf\n", mat[each][n] / mat[each][each]);
      }
    }
  }
  return 0;
}
