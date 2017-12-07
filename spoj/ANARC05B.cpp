#include <iostream>

using namespace std;

const int maxn = 10000;
int v[2][maxn+5];
int sum[2][maxn+5];

int main() {
  ios::sync_with_stdio(false);
  int n, n0, n1;
  while(true) {
    cin >> n0;
    if(!n0)
      break;
    for(int i = 0; i < n0; i++)
      cin >> v[0][i];
    cin >> n1;
    for(int i = 0; i < n1; i++)
      cin >> v[1][i];
    int i0 = 0, i1 = 0;
    int s0 = 0, s1 = 0    ;
    n = 0;
    while(i0 < n0 || i1 < n1) {
      if(i0 == n0) {
	s1 += v[1][i1++];
	continue;
      } else if(i1 == n1) {
	s0 += v[0][i0++];
	continue;
      }
      if(v[0][i0] < v[1][i1]) {
	s0 += v[0][i0++];
      } else if(v[0][i0] > v[1][i1]) {
	s1 += v[1][i1++];
      } else {
	s0 += v[0][i0++];
	s1 += v[1][i1++];
	sum[0][n] = s0;
	sum[1][n] = s1;
	n++;
	s0 = 0;
	s1 = 0;
      }
    }
    sum[0][n] = s0;
    sum[1][n] = s1;
    n++;
    int d0 = sum[0][0];
    int d1 = sum[1][0];
    for(int i = 1; i < n; i++) {
      int d00 = max(d0, d1) + sum[0][i];
      int d11 = max(d0, d1) + sum[1][i];
      d0 = d00;
      d1 = d11;
    }
    cout << max(d0, d1) << endl;
  }
  return 0;
}
