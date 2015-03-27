#include <stack>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int chief[500001];
map<int, vector<int> > sub;
stack<int> topoSorted;

void topoVisit(int u) {
  vector<int> curSub = sub[u];
  for(int i= 0; i < curSub.size(); i++) {
    topoVisit(curSub[i]);
  }
  topoSorted.push(u);
}

int main() {
  ifstream ifs("grant.in");
  ofstream ofs("grant.out");
  memset(chief, 0, sizeof chief);
  int n;
  ifs >> n;
  for(int i= 2; i <= n; i++) {
    int x;
    ifs >> x;
    chief[i] = x; 
    if(sub.count(x) == 0) {
      vector<int> singleton;
      singleton.push_back(i);
      sub[x] = singleton;
    } else
      sub[x].push_back(i);
  }
  topoVisit(1);
  vector<int> assigned;
  bool picked[n+1];
  memset(picked, false, sizeof picked);
  while(!topoSorted.empty()) {
    int next = topoSorted.top();
    topoSorted.pop();
    if(next == 1)
      continue;
    if(!picked[next] && !picked[chief[next]]) {
      assigned.push_back(next);
      picked[next] = true;
      picked[chief[next]] = true;
    }
  }
  ofs << ((long long) assigned.size()) * 1000 << endl;
  sort(assigned.begin(), assigned.end());
  for(int i= 0; i < assigned.size(); i++) {
    if(i != 0)
      ofs << " " << assigned[i];
    else
      ofs << assigned[i];
  }
  ofs << endl;
  return 0;
}
