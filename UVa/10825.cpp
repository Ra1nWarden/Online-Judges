#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int m, n;
vector<int> candidate;

void generate(int base) {
  candidate.clear();
  candidate.push_back(base);
  for(int i = 2; i <= m; i++) {
    candidate.push_back((base * i) % n);
  }
  sort(candidate.begin(), candidate.end());
}

vector<int> mult(int fact) {
  vector<int> ans;
  int carry = 0;
  for(int i = 0; i < candidate.size(); i++) {
    int res = candidate[i] * fact + carry;
    carry = res / n;
    res = res % n;
    ans.push_back(res);
  }
  return ans;
}

bool match(vector<int> cmp1, vector<int> cmp2) {
  sort(cmp1.begin(), cmp1.end());
  sort(cmp2.begin(), cmp2.end());
  for(int i = 0; i < cmp1.size(); i++) {
    if(cmp1[i] != cmp2[i])
      return false;
  }
  return true;
}

bool test() {
  for(int i = 2; i <= m; i++) {
    vector<int> res = mult(i);
    if(!match(res, candidate)) {
      return false;
    }
  }
  return true;
}

int main() {
  while(scanf("%d%d", &m, &n) != EOF && (m || n)) {
    bool found = false;
    for(int i = 1; i < n; i++) {
      generate(i);
      do {
	if(test()) {
	  found = true;
	  break;
	}
      } while(next_permutation(candidate.begin(), candidate.end()));
      if(found)
	break;
    }
    if(found) {
      for(int i = 0; i < candidate.size(); i++) {
	if(i > 0)
	  printf(" ");
	printf("%d", candidate[candidate.size() - 1 - i]);
      }
      printf("\n");
    } else {
      printf("Not found.\n");
    }
  }
  return 0;
}
