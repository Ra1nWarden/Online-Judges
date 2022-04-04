#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> II;

const int mod = 1000000007;
const int maxn = 363304;
II v[maxn+5];
int n;
char command[10];

int main() {
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    scanf("%s %d\n", command, &v[i].second);
    v[i].first = command[1] == 'C';
  }

  vector<int> pv;
  priority_queue<int, vector<int>, greater<int> > sell;
  priority_queue<int> buy;
  int ans = 1;

  for(int i = 0; i < n; i++) {
    //printf("i=%d\n", i);
    if(v[i].first) {
      //printf("accept %d\n", v[i].second);
      //printf("buy %d sell %d\n", buy.size(), sell.size());
      if((!buy.empty() && v[i].second < buy.top()) || (!sell.empty() && v[i].second > sell.top())) {
	//printf("buy.top()=%d zero\n", buy.top());
	ans = 0;
	break;
      }
      if(!buy.empty() && v[i].second == buy.top()) {
	buy.pop();
      } else if(!sell.empty() && v[i].second == sell.top()) {
	sell.pop();
      } else {
	ans = (ans * 2) % mod;
      }
      for(int j = 0; j < pv.size(); j++) {
	if(pv[j] < v[i].second) {
	  buy.push(pv[j]);
	} else if(pv[j] > v[i].second) {
	  sell.push(pv[j]);
	}
      }
      pv.clear();
    } else {
      //printf("add %d\n", v[i].second);
      if(!buy.empty() && v[i].second < buy.top()) {
	buy.push(v[i].second);
      } else if(!sell.empty() && v[i].second > sell.top()) {
	sell.push(v[i].second);
      } else {
	pv.push_back(v[i].second);
      }
    }
  }

  ans = (ans * 1LL * (pv.size() + 1)) % mod;

  printf("%d\n", ans);

  return 0;
}
