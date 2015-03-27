#include <iostream>
#include <cstring>
#define MAXN 60
#define MAXL 200005

using namespace std;

int cv[MAXN];
bool used[MAXL];

int main() {
  string s, t;
  getline(cin, s);
  getline(cin, t);
  memset(cv, 0, sizeof cv);
  for(int i= 0; i < t.length(); i++) {
    cv[t[i] - 'A']++;
  }
  int resa = 0;
  int resb = 0;
  memset(used, false, sizeof used);
  for(int i= 0; i < s.length(); i++) {
    if(cv[s[i] - 'A'] > 0) {
      resa++;
      cv[s[i] - 'A']--;
      used[i] = true;
    }
  }
  for(int i = 0; i < s.length(); i++) {
    if(!used[i]) {
      if(tolower(s[i]) == s[i] && cv[toupper(s[i]) - 'A'] > 0) {
	resb++;
	cv[toupper(s[i]) - 'A']--;
      } else if(tolower(s[i]) != s[i] && cv[tolower(s[i]) - 'A'] > 0) {
	resb++;
	cv[tolower(s[i]) - 'A']--;
      }
    }
  }
  cout << resa << " " << resb << endl;
  return 0;
}
