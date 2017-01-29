#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int maxl = 100;
char str[maxl+5];
char v[4];
int l;

int main() {
  set<char> s;
  s.insert('R');
  s.insert('G');
  s.insert('B');
  s.insert('Y');
  scanf("%s", str);
  memset(v, 0, sizeof v);
  l = strlen(str);
  for(int i = 0; i < l; i++) {
    if(str[i] != '!') {
      v[i%4] = str[i];
      s.erase(str[i]);
    }
  }
  set<char>::iterator itr = s.begin();
  for(int i = 0; i < 4; i++) {
    if(v[i] == 0) {
      v[i] = *itr;
      itr++;
    }
  }
  int r = 0, g = 0, b = 0, y = 0;
  for(int i = 0; i < l; i++) {
    if(str[i] == '!') {
      if(v[i%4] == 'R')
	r++;
      if(v[i%4] == 'G')
	g++;
      if(v[i%4] == 'B')
	b++;
      if(v[i%4] == 'Y')
	y++;
    }
  }
  printf("%d %d %d %d\n", r, b, y, g);
  return 0;
}
