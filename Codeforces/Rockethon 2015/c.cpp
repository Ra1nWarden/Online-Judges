#include <cstdio>
#include <vector>
#define MAXN 5

using namespace std;

int v[MAXN][2];
int n;

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &v[i][0], &v[i][1]);
  }
  long long total = 0;
  for(int i = 0; i < n; i++) {
    for(int j = v[i][0]; j <= v[i][1]; j++) {

      // second highest price is j
      long long count = 0;
      // First case, someone is strictly higher than me
      for(int k = 0; k < n; k++) {
	if(k == i)
	  continue;
	if(v[k][1] > j) {
	  int subcounter = 0;
	  long long subcount = 1;
	  for(int l = 0; l < n; l++) {
	    if(l == i || l == k)
	      continue;
	    if(l < i) {
	      if(v[l][0] <= j) {
		subcounter++;
		subcount *= (min(j, v[l][1]) - v[l][0] + 1);
	      }
	    } else {
	      if(v[l][0] < j) {
		subcounter++;
		subcount *= (min(j - 1, v[l][1]) - v[l][0] + 1);
	      }
	    }
	  }
	  if(subcounter == n - 2) {

	    count += (subcount * (v[k][1] - max(j+1, v[k][0]) + 1));
	  }
	}
      }

      // second case, a tie
      bool ok = true;
      for(int k = 0; k < n; k++) {
	if(k == i)
	  continue;
	if(v[k][0] > j) {
	  ok = false;
	  break;
	}
      }
      if(ok) {
	long long subtotal1 = 1;
	for(int k = 0; k < n; k++) {
	  if(k == i)
	    continue;
	  if(k < i) {
	    subtotal1 *= (min(v[k][1], j) - v[k][0] + 1);
	  } else {
	    subtotal1 *= (min(v[k][1], j - 1) - v[k][0] + 1);
	  }
	}
	long long subtotal2 = 1;
	for(int k = 0; k < n; k++) {
	  if(k == i)
	    continue;
	  subtotal2 *= (min(v[k][1], j - 1) - v[k][0] + 1);
	}
	if(subtotal2 < subtotal1) {
	  count += (subtotal1 - subtotal2);
	}
      }
   
      total += (count * j);
 
    }
  }
  double div = 1.0;
  for(int i = 0; i < n; i++) {
    div *= (v[i][1] - v[i][0] + 1);
  }

  printf("%.10lf\n", total / div);

  return 0;
}
