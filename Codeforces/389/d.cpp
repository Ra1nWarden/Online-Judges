#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

const int maxn = 100000;
char str[maxn+5];
map<string, priority_queue<int> > m;
set<string> visited;
int k, n, b;

int main() {
  scanf("%d %d\n", &k, &n);
  for(int i = 0; i < k; i++) {
    scanf("%s %d\n", str, &b);
    string w(str);
    if(m.count(w)) {
      m[w].push(b);
    } else {
      priority_queue<int> pq;
      pq.push(b);
      m[w] = pq;
    }
  }
  int ans = 0;
  int all_ans = 0;
  for(map<string, priority_queue<int> >::iterator itr = m.begin(); itr != m.end(); itr++) {
    string orig = itr->first;
    string rev = orig;
    reverse(rev.begin(), rev.end());
    if(m.count(rev) == 0 || visited.count(orig)) {
      continue;
    }
    if(rev != orig) {
      priority_queue<int> orig_cnt = m[orig];
      priority_queue<int> rev_cnt = m[rev];
      while(!orig_cnt.empty() && !rev_cnt.empty()) {
	int add = orig_cnt.top() + rev_cnt.top();
	orig_cnt.pop();
	rev_cnt.pop();
	if(add <= 0)
	  break;
	else
	  ans += add;
      }
      visited.insert(orig);
      visited.insert(rev);
    } else {
      priority_queue<int> cnt = m[orig];
      while(!cnt.empty()) {
	int add1 = cnt.top();
	cnt.pop();
	if(!cnt.empty()) {
	  int add2 = cnt.top();
	  cnt.pop();
	  if(add1 + add2 > 0) {
	    ans += add1 + add2;
	  }
	}
      }
      visited.insert(orig);
    }
  }
  all_ans = ans;
  for(map<string, priority_queue<int> >::iterator itr = m.begin(); itr != m.end(); itr++) {
    int cur = ans;
    string orig = itr->first;
    string rev = orig;
    reverse(rev.begin(), rev.end());
    if(m.count(rev) == 0 || orig != rev) {
      continue;
    }
    priority_queue<int> cnt = m[orig];
    int sub = 0;
    while(!cnt.empty()) {
      int add1 = cnt.top();
      cnt.pop();
      if(!cnt.empty()) {
	int add2 = cnt.top();
	cnt.pop();
	if(add1 + add2 > 0) {
	  sub += add1 + add2;
	}
      }
    }
    cnt = m[orig];
    int sub2 = 0;
    while(!cnt.empty()) {
      int add = cnt.top();
      cnt.pop();
      if(add > 0)
	sub2 += add;
    }
    if(sub2 > sub) {
      all_ans = max(all_ans, cur + sub2 - sub);
    }
  }
  printf("%d\n", all_ans);
  return 0;
}
