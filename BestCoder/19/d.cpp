#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p[100001][2];
int w[100001][2];

vector<int> findpath(int s, int e, int t) {
  vector<int> sv;
  while(s != 1) {
    sv.push_back(s);
    s = p[s][t];
  }
  sv.push_back(1);
  vector<int> ev;
  while(e != 1) {
    ev.push_back(e);
    e = p[e][t];
  }
  ev.push_back(1);

  vector<int> result;
  int ii = 1;
  for(int i= 1; i <= min(sv.size(), ev.size()); i++) {
    if(sv[sv.size() - i] != ev[ev.size() - i]) {
      ii = i;
      break;
    }
  }
  result.push_back(sv.size() - ii + 1);
  result.insert(result.end(), sv.begin(), sv.begin() + sv.size() - ii);
  result.insert(result.end(), ev.begin(), ev.begin() + ev.size() - ii);
  return result;
}

int countIntersection(const vector<int>& a, const vector<int>& b) {
  int result = 0;
  int bi = 0;
  int ai = 0;
  while(true) {
    if(bi >= b.size() || ai >= a.size())
      break;
    if(a[ai] == b[bi]) {
      result++;
      ai++;
      bi++;
    } else if(a[ai] > b[bi])
      bi++;
    else
      ai++;
  }
  return result;
}

int main() {
  int n1, n2;
  while(cin >> n1) {
    for(int i = 1; i <= n1 - 1; i++) {
      int parent;
      cin >> parent;
      p[i+1][0] = parent;
    }
    for(int i=  1; i <= n1; i++) {
      int weight;
      cin >> weight;
      w[i][0] = weight;
    }
    cin >> n2;
    for(int i = 1; i <= n2 - 1; i++) {
      int parent;
      cin >> parent;
      p[i+1][1] = parent;
    }
    for(int i=  1; i <= n2; i++) {
      int weight;
      cin >> weight;
      w[i][1] = weight;
    }
    int q;
    cin >> q;
    for(int i= 0; i < q; i++) {
      int u1, v1, u2, v2;
      cin >> u1 >> v1 >> u2 >> v2;
      vector<int> path1 = findpath(u1, v1, 0);
      vector<int> path2 = findpath(u2, v2, 1);
      vector<int> val1;
      for(int j = 0; j < path1.size(); j++) {
	val1.push_back(path1[j]);
      }
      vector<int> val2;
      for(int j= 0; j < path2.size(); j++) {
	val2.push_back(path2[j]);
      }
      sort(val1.begin(), val1.end());
      sort(val2.begin(), val2.end());
      cout << countIntersection(val1, val2) << endl;
    }
  }
  return 0;
}
