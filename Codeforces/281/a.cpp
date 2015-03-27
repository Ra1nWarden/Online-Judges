#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int home[100];
bool hgive[100];
int away[100];
bool agive[100];
string h, a;

int main() {
  memset(home, 0, sizeof home);
  memset(away, 0, sizeof away);
  memset(hgive, false, sizeof hgive);
  memset(agive, false, sizeof agive);
  getline(cin, h);
  getline(cin, a);
  int n;
  cin >> n;
  for(int i= 0; i < n; i++) {
    int t, num;
    char team, card;
    cin >> t >> team >> num >> card;
    int add = card == 'y' ? 1 : 2;
    if(team == 'a') {
      away[num] += add;
      if(away[num] > 1 && !agive[num]) {
	printf("%s %d %d\n", a.c_str(), num, t);
	agive[num] = true;
      }
    } else {
      home[num] += add;
      if(home[num] > 1 && !hgive[num]) {
	printf("%s %d %d\n", h.c_str(), num, t);
	hgive[num] = true;
      }
    }
  }
}
