#include <iostream>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

static const long long mod = 1000000007;

int facts[30001];

int main() {
  memset(facts, -1, sizeof facts);
  facts[0] = 1;
  for(int i = 1; i < 30001; i++) {
    long long mult = (long long) facts[i - 1] * (long long) i;
    if (mult > mod)
      mult %= mod;
    facts[i] = mult;
  }
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int v[a];
    for(int j = 0; j < a; j++) {
      int c;
      cin >> c;
      v[j] = c;
    }
    vector<pair<int, int> > queries;
    map<int, map<int, int> > counts;
    map<int, int> dummy;
    for(int j = 0; j < b; j++) {
      int start, end;
      cin >> start >> end;
      queries.push_back(make_pair(start, end));
      if(!counts.count(start)) {
	counts[start] = dummy;
      }
      if(!counts.count(end)) {
	counts[end] = dummy;
      }
    }
    map<int, int> rm;
    for(int j = 1; j <= a; j++) {
      int c = v[j-1];
      if(rm.count(c))
	rm[c] = rm[c] + 1;
      else
	rm[c] = 1;
      if(counts.count(j))
	counts[j] = rm;
    }
    for(int j = 0; j < queries.size(); j++) {
      map<int, int> endm = counts[queries[j].second];
      map<int, int> startm = counts[queries[j].first];
      map<int, int> rangem;
      int start = queries[j].first;
      int end = queries[j].second;
      int result = facts[end - start + 1];
      for(map<int, int>::iterator itr = endm.begin(); itr != endm.end(); itr++) {
	int mult = itr->second - startm[itr->first];
	if(v[start - 1] == itr->first)
	  mult++;
	result /= facts[mult];
      }
      cout << result << endl;
    }
  }
  return 0;
}
