#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#define MAXN 105

using namespace std;

typedef pair<string, int> Person;

Person ppl[MAXN];
int n;

bool _cmp(const Person& a, const Person& b) {
  return a.second > b.second;
}

int main() {
  string line;
  ios::sync_with_stdio(false);
  int tc;
  getline(cin, line);
  stringstream ss(line.c_str());
  ss >> tc;
  while(tc--) {
    getline(cin, line);
    stringstream sss(line.c_str());
    sss >> n;
    for(int i = 0; i < n; i++) {
      getline(cin, line);
      int j;
      for(j = line.length() - 1; j >= 0; j--) {
	if(line[j] == ' ')
	  break;
      }
      int len;
      ppl[i].first = "";
      for(len = 0; len < j && ppl[i].first.length() < 100; len++) {
	if(isspace(line[len]) || isalnum(line[len])) {
	  ppl[i].first += line[len];
	}
      }
      ppl[i].second = atoi(line.substr(j + 1).c_str());
    }
    sort(ppl, ppl + n, _cmp);
    for(int i = 0; i < n; i++)
      cout << ppl[i].first << endl;
  }
  return 0;
}
