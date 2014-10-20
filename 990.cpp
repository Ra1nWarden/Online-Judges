#include <iostream>
#include <cstring>
#include <map>
#include <utility>
#include <vector>

using namespace std; 

struct Item {
  Item() {};
  Item(int a, int b) : w(a), p(b) {};
  int w, p;
};

Item items[30];
map<pair<int, int>, vector<int> > dp;
map<pair<int, int>, int> dpVal;

vector<int> knapsack(int i, int j) {
  if(dp.count(make_pair(i, j)) != 0)
    return dp[make_pair(i, j)];
  vector<int> result;
  int resultVal = 0;
  if(i != 0 && j != 0) {
    if(items[i-1].w > j) {
      result = knapsack(i-1, j);
      resultVal = dpVal[make_pair(i-1, j)];
    } else {
      vector<int> take = knapsack(i-1, j - items[i-1].w);
      int takeVal = dpVal[make_pair(i-1, j-items[i-1].w)];
      take.push_back(i-1);
      takeVal += items[i-1].p;
      vector<int> nottake = knapsack(i-1, j);
      int nottakeVal = dpVal[make_pair(i-1, j)];
      if(takeVal > nottakeVal) {
	result = take;
	resultVal = takeVal;
      } else {
	// nottake > take
	result = nottake;
	resultVal = nottakeVal;
      }
    }
  }
  dp[make_pair(i, j)] = result;
  dpVal[make_pair(i, j)] = resultVal;
  return result;
}

int main() {
  int t, w, n;
  bool start = true;
  while(cin >> t >> w >> n) {
    if(!start)
      cout << endl;
    dp.clear();
    dpVal.clear();
    for(int i = 0; i < n; i++) {
      int d, v;
      cin >> d >> v;
      items[i].w = d * 3 * w;
      items[i].p = v;
    }
    vector<int> result = knapsack(n, t);
    int resultVal = dpVal[make_pair(n, t)];
    cout << resultVal << endl << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
      cout << items[result[i]].w / (3*w) << " " << items[result[i]].p << endl;
    start = false;
  }
  return 0;
}
