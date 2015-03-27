#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++) {
    if(i % 2 == 0) {
      string line(m, '#');
      cout << line << endl;
    } else {
      if(i % 4 == 1) {
	string line(m, '.');
	line[m-1] = '#';
	cout << line << endl;
      } else {
	string line(m, '.');
	line[0] = '#';
	cout << line << endl;
      }
    }
  }
  return 0;
}
