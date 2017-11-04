#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

const int maxn = 100000;
const int maxl = 1000000;
string strs[maxn+5];
int n;
int v[maxl+5];
vector<int> all_pos;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> ws;
  memset(v, -1, sizeof v);
  int rl = 0;
  for(int i = 0; i < n; i++) {
    cin >> strs[i];
    int cnt;
    cin >> cnt;
    int pos;
    for(int j = 0; j < cnt; j++) {
      cin >> pos;
      pos--;
      if(v[pos] == -1) {
	v[pos] = i;
	all_pos.push_back(pos);
      }
      else
	v[pos] = strs[i].length() > strs[v[pos]].length() ? i : v[pos];
      rl = max(rl, pos + (int) strs[i].length());
    }
  }

  sort(all_pos.begin(), all_pos.end());

  stringstream ss;
  vector<int>::iterator itr = all_pos.begin();
  for(int i = 0; i < rl || itr < all_pos.end();) {
    if(i == rl)
      break;
    if(itr == all_pos.end() || *itr > i) {
      ss << 'a';
      i++;
      continue;
    }
    int il = *itr + strs[v[*itr]].length();
    if(il > i) {
      ss << strs[v[*itr]][i - *itr];
      i++;
      continue;
    }
    if(il <= i) {
      itr++;
      continue;
    }
  }
  cout << ss.str() << endl;
  return 0;
}
