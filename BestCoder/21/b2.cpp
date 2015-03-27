#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

static const int n = 1000000007;
static const int MAXN = 10000001;

int main() {
  int x;
  vector<int> cases;
  set<int> sorted;
  while(cin >> x) {
    cases.push_back(x);
    sorted.insert(x);
  }
  map<int, int> sol;
  int result = 1;
  int resultc = 1;
  int index = 1;
  for(set<int>::iterator itr = sorted.begin(); itr != sorted.end(); itr++) {
    int threshold = *itr;
    for(int i = index; i <= threshold; i++) {
      resultc = (long long) resultc * (long long) i % n;
      result = (long long) result * (long long) resultc % n;
    }
    sol[threshold] = result;
    index = threshold + 1;
  }

  for(int i= 0; i < cases.size(); i++) {
    cout << sol[cases[i]] << endl;
  }

  return 0;
}
