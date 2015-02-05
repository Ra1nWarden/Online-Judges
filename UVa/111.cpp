#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

bool coordinate[101][101];

int main() {
  int n;
  cin >> n >> ws;
  string line;
  getline(cin, line);
  istringstream iss(line.c_str());
  vector<int> correct(n, -1);
  int x;
  for(int i= 1; i <= n; i++) {
    iss >> x;
    correct[x - 1] = i;
  }
  memset(coordinate, false, sizeof coordinate);
  for(int i = 1; i < n ; i++) {
    for(int j = 0; j < i; j++) {
      coordinate[correct[j]][correct[i]] = true;
    }
  }
  while(getline(cin, line)) {
    istringstream iss(line.c_str());
    vector<int> student(n, -1);
    for(int i = 1; i <= n; i++) {
      iss >> x;
      student[x-1] = i;
    }
    int result = 1;
    vector<int> lcs(n, 1);
    for(int i = 1; i < n; i++) {
      for(int j = 0; j < i ; j++) {
	if(coordinate[student[j]][student[i]]) {
	  lcs[i] = max(lcs[i], 1+lcs[j]);
	  if(lcs[i] > result)
	    result = lcs[i];
	}
      }
    }
    cout << result << endl;
  }
  return 0;
}
