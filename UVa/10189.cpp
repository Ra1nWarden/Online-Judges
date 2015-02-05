#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  int index = 1;
  while(true){
    int m, n;
    cin >> m >> n;
    if(m ==0 && n == 0)
      break;
    if(index > 1)
      cout << endl;
    int result[m][n];
    for(int i = 0; i < m; i++) {
      for(int j = 0 ; j < n; j++) {
	result[i][j]=0;
      }
    }
    for(int i = 0; i < m; i++) {
      string line;
      cin >> line;
      istringstream in (line.c_str());
      for(int j = 0; j < n; j++) {
	char current;
	in >> current;
	if(current == '*') {
	  result[i][j] = -1;
	  for(int k = i - 1; k <= i+1; k++) {
	    if(k < 0 || k >= m)
	      continue;
	    for(int l = j - 1; l <= j+1; l++) {
	      if(l < 0 || l >= n)
		continue;
	      if(k == i && l == j)
		continue;
	      if(result[k][l]!=-1)
		result[k][l]++;
	    }
	  }
	}
      }
    }
    cout << "Field #" << index << ":" << endl;
    for(int i = 0; i < m; i++) {
      for(int j =0; j < n; j++) {
	if(result[i][j]==-1)
	  cout << "*";
	else
	  cout << result[i][j];
      }
      cout << endl;
    }
  index++;
  }
  return 0;
}
