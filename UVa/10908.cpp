#include <iostream>

using namespace std;

bool DEBUG = false;

int main() {
  int tc;
  cin >> tc;
  while(tc--) {
    int a, b, n;
    cin >> a >> b >> n >> ws;
    string line;
    char grid[a][b];
    for(int i = 0; i < a; i++) {
      getline(cin, line);
      for(int j = 0; j < b; j++) {
	grid[i][j] = line[j];
      }
    }
    cout << a << " " << b << " " << n << endl;
    for(int i= 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      int result = 1;
      char test = grid[x][y];
      if(DEBUG)
	cout << "test char is " << test << " for " << x << ", " << y << endl;
      for(int j= 1; j > 0; j++) {
	if(x - j < 0 || y - j < 0 || x + j > a-1 || y + j > b-1) {
	  break;
	}
	bool success = true;
	if(DEBUG)
	  cout << "looping from (" << x-j << ", " <<  y+j << ") to (" << x+j << ", " << y+j << ") test char is " << test << endl; 
	for(int l = x - j; l <= x + j; l++) {
	  for(int m = y - j; m <= y + j; m++) {
	    if(grid[l][m] != test) {
	      success = false;
	      break;
	    }
	  }
	  if(!success)
	    break;
	}
	if(success) {
	  result = 1 + 2*j;
	}
	else {
	  break;
	}
      }
      cout << result << endl;
    }
  }
  return 0;
}
