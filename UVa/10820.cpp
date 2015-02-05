#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

bool prime[50001];
int ans[50001];
map<int, vector<int> > factm;

int f(int x) {
  if(ans[x] != -1)
    return ans[x];
  vector<int> facts = factm[x];
  int result = x;
  for(int i= 0; i < facts.size(); i++) {
    //cout << x << " has factor " << facts[i] << endl;
    result = result / facts[i] * (facts[i] - 1);
  }
  //cout << "answer for " << x << " is " << result << endl;
  return ans[x] = result;
}

void insertOrAdd(int a, int b) {
  if(factm.count(a) == 0) {
    vector<int> singleton;
    singleton.push_back(b);
    factm[a] = singleton;
  } else
    factm[a].push_back(b);
}

int main() {
  memset(prime, true, sizeof prime);
  for(int i= 2; i <= 50000; i++) {
    if(prime[i]) {
      insertOrAdd(i, i);
      for(int j= i+i; j <= 50000; j+=i) {
	prime[j] = false;
        insertOrAdd(j, i);
      }
    }
  }

  memset(ans, -1, sizeof ans);
  int n;
  while(cin >> n && n) {
    int result = 0;
    for(int i = 2; i <= n; i++) {
      result += f(i);
    }
    result *= 2;
    result += 1;
    cout << result << endl;
  }
  return 0;
}
