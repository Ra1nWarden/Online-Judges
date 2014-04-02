#include <vector>
#include <iostream>

using namespace std;

void updateGrid(vector<vector<bool> >& grid, int i, int j) {
  int row = grid.size();
  int col = grid[0].size();
  grid[i][j] = false;
  for(int ii = 0; ii < i; ii++) {
    for(int jj = 0; jj < col; jj++)
      grid[ii][jj] = false;
  }
  for(int jj = 0; jj < j; jj++)
    grid[i][jj] = false;
  int diff = 1;
  // SW
  while(i+diff < row && j-diff >= 0) {
    grid[i+diff][j-diff] = false;
    diff++;
  }
  diff = 1;
  // SE 
  while(i+diff < row && j+diff < col) {
    grid[i+diff][j+diff] = false;
    diff++;
  }
}

bool checkAvailability(vector<vector<bool> >& grid, int left) {
  int row = grid.size();
  int col = grid[0].size();
  int count = 0;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(grid[i][j])
	count++;
    }
  }
  return count >= left;
}

int count(vector<vector<bool> >& grid, int left) {
  int result = 0;
  int row = grid.size();
  int col = grid[0].size();
  if(left == 1) {
    for(int i = 0; i< row; i++) {
      for(int j = 0; j< col; j++) {
	if(grid[i][j]) 
	  result++;
      }
    }
    return result;
  }
  else {
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
	if(grid[i][j]) {
	  vector<vector<bool> > copied = grid;
	  updateGrid(copied, i, j);
	  if(checkAvailability(copied, left-1))
	    result += count(copied, left-1);
	}
      }
    }
    return result;
  }
}

int main() {
  while(true) {
    int n, k;
    cin >> n >> k;
    if(n == 0 && k == 0)
      break;
    else if(k == 0) {
      cout << 1 << endl;
      continue;
    }
    vector<vector<bool> > grid;
    for(int i = 0; i < n; i++) {
      vector<bool> row(n);
      for(int j = 0; j < n; j++)
	row[j] = true;
      grid.push_back(row);
    }
    cout << count(grid, k) << endl;
   }
  return 0;
}
