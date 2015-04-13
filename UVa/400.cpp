#include <iostream>
#include <string>
#include <algorithm>
#define MAXN 105

using namespace std;

string filenames[MAXN];

void print(const string& s, int len, char extra) {
  cout << s;
  for(int i = 0; i < len - s.length(); i++) {
    cout << extra;
  }
}

int n;

int main() {
  while(cin >> n >> ws) {
    int maxl = 0;
    for(int i = 0; i < n; i++) {
      getline(cin, filenames[i]);
      maxl = max(maxl, (int) filenames[i].length());
    }
    int cols = (60 - maxl) / (maxl + 2) + 1;
    int rows = (n - 1) / cols + 1;
    print("", 60, '-');
    cout << endl;
    sort(filenames, filenames+n);
    for(int i = 0; i < rows; i++) {
      for(int j = 0; j < cols; j++) {
	int index = j * rows + i;
	if(index < n)
	  print(filenames[index], j == cols - 1 ? maxl : maxl+2, ' ');
      }
      cout << endl;
    }
  }
  return 0;
}

