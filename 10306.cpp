#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct coin {
  int x, y;
  int coincount; // This one does not seem to be necessary after optimization
  coin(int a, int b):x(a),y(b),coincount(1){};
};

int main() {
  int cases;
  cin >> cases;
  for(int i = 0; i < cases; i++) {
    int coinno, target;
    cin >> coinno >> target;
    vector<coin*> coins;
    queue<coin*> myqueue;
    vector<vector<int> > mincount;
    for(int j = 0; j <= target+1; j++) {
      vector<int> pushin;
      for(int k = 0; k <= target+1; k++)
	pushin.push_back(0);
      mincount.push_back(pushin);
    }
    int result = 0;
    for(int j = 0; j < coinno; j++) {
      int a, b;
      cin >> a >> b;
      coin* curcoin = new coin(a, b);
      coins.push_back(curcoin);
      myqueue.push(curcoin);
      mincount[a][b] = 1;
    }
    while(!myqueue.empty()) {
      coin* current = myqueue.front();
      myqueue.pop();
      for(int j = 0; j < coinno; j++) {
	coin* next = coins[j];
	int newx = next->x + current->x;
	int newy = next->y + current->y;
	if(pow(newx, 2) + pow(newy, 2) == pow(target, 2)) {
	  result = current->coincount + 1;
	  break;
	}
	else if(pow(newx, 2) + pow(newy, 2) < pow(target, 2)) {
	  if(mincount[newx][newy] == 0) {
	    coin* nextcoin = new coin(newx, newy);
	    nextcoin->coincount = current->coincount + 1;
	    mincount[newx][newy] = nextcoin->coincount;
	    myqueue.push(nextcoin);
	  }
	}
      }
      if(result != 0)
	break;
    }
    if(result == 0)
      cout << "not possible" << endl;
    else
      cout << result << endl;
  }
  return 0;
}
