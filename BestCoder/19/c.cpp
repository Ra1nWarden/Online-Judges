#include <vector>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

typedef pair<pair<int, int>, int> coord;

int main() {
  int n, m, q;
  while(cin >> n >> m >> q >> ws) {
    map<coord, int> memo;
    vector<string> board;
    string line;
    for(int i = 0; i < n; i++) {
      getline(cin, line);
      board.push_back(line);
    }
    for(int i = 0; i < q; i++) {
      int x, y, d;
      cin >> x >> y >> d;
      x -= 1;
      y -= 1;
      if(memo.count(make_pair(make_pair(x, y), d))) {
	cout << memo[make_pair(make_pair(x, y), d)] << endl;
	continue;
      }
      int result = 0;
      for(int j = x; j >= 0; j -= d) {
	for(int k = y - (x - j); k <= y + (x - j); k++) {
	  //cout << "inspecting " << j << ", " << k << endl;
	  if(k < 0)
	    continue;
	  if(k >= m)
	    break;
	  if(board[j][k] == 'X')
	    result++;
	}
      }
      memo[make_pair(make_pair(x, y), d)] = result;
      cout << result << endl;
    }
  }
  return 0;
}
