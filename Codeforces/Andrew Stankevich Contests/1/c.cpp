#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int chief[500001];
int dp[500001][2];
map<int, vector<int> > sub;
int picked[500001];

int f(int i, int x) {
  if(dp[i][x] != -1)
    return dp[i][x];
  int maxVal;
  if(x == 0) {
    // assign
    maxVal = 0;
    if(sub.count(i) != 0) {
      vector<int> curSub = sub[i];
      for(int j= 0; j < curSub.size(); j++) {
	int nextAssign = curSub[j];
	int nextVal = f(nextAssign, 1);
	for(int k = 0; k < curSub.size(); k++) {
	  if(j == k)
	    continue;
	  nextVal += f(curSub[k], 0);
	}
	if(nextVal > maxVal) {
	  maxVal = nextVal;
	  picked[i] = nextAssign;
	}
      }
    }

  } else {
    // being assigned
    maxVal = 1;
    if(sub.count(i) != 0) {
      vector<int> curSub = sub[i];
      for(int j= 0; j < curSub.size(); j++) {
	maxVal += f(curSub[j], 0);
      }
    }
  }
  dp[i][x] = maxVal;
  return maxVal;
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
  memset(dp, -1, sizeof dp);
  memset(picked, -1, sizeof picked);
  long long result = (long long) f(1,0);
  ofs << result * 1000 << endl;
  set<int> resultPicked;
  queue<int> q;
  q.push(1);
  while(!q.empty()) {
    int next = q.front();
    q.pop();
    vector<int> nextSub = sub[next];

    if(picked[next] != -1) {
      //cout << next << " picked " << picked[next] << endl;
      resultPicked.insert(picked[next]);
    }
    for(int i = 0; i < nextSub.size(); i++) {
      if(nextSub[i] != picked[next])
	q.push(nextSub[i]);
    }
    vector<int> pickedSub = sub[picked[next]];
    for(int i= 0; i < pickedSub.size(); i++)
      q.push(pickedSub[i]);
  }
  for(set<int>::iterator itr = resultPicked.begin(); itr != resultPicked.end(); itr++) {
    if(itr != resultPicked.begin())
      ofs << " " << *itr;
    else
      ofs << *itr;
  }
  ofs << endl;
  return 0;
}
